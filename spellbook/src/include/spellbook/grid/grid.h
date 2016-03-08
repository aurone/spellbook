////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014, Andrew Dornbush All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
////////////////////////////////////////////////////////////////////////////////

#ifndef au_grid_h
#define au_grid_h

#include <assert.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <type_traits>
#include <vector>

namespace au
{

template <int N, typename T>
class grid
{
public:

    class grid_iterator;
    class grid_index;

    typedef std::size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef grid_iterator iterator;
    typedef const grid_iterator const_iterator;

    grid();

    template <typename... sizes>
    grid(sizes... counts);

    grid(const grid& other);
    grid& operator=(const grid& rhs);

    grid(grid&& other);
    grid& operator=(grid&& rhs);

    ~grid();

    /// \name Element access
    ///@{
    template <typename... CoordTypes>
    reference operator()(CoordTypes... coords);

    template <typename... CoordTypes>
    const_reference operator()(CoordTypes... coords) const;

    template <typename... CoordTypes>
    reference at(CoordTypes... coords);

    template <typename... CoordTypes>
    const_reference at(CoordTypes... coords) const;

    template <typename... CoordTypes>
    reference operator()(const grid_index& index);

    template <typename... CoordTypes>
    const_reference operator()(const grid_index& index) const;

    template <typename... CoordTypes>
    reference at(const grid_index& index);

    template <typename... CoordTypes>
    const_reference at(const grid_index& index) const;

    T* data() { return data_; }

    template <typename... CoordTypes>
    bool within_bounds(CoordTypes... coords) const;
    ///@}

    /// \name Iterators
    ///@{
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    iterator grid_begin(const grid_index& start, const grid_index& end);
    const_iterator grid_begin(const grid_index& start, const grid_index& end) const;
    iterator grid_end(const grid_index& start, const grid_index& end);
    const_iterator grid_end(const grid_index& start, const grid_index& end) const;
    ///@}

    /// \name Capacity
    ///@{
    size_type size(size_type dim) const;
    size_type total_size() const;
    ///@}

    /// \name Modifiers
    ///@{
    void clear();

    template <typename... SizeTypes>
    void resize(SizeTypes... sizes);

    void assign(const T& value);
    ///@}

    class grid_index
    {
    public:

        grid_index();

        template <typename... CoordTypes>
        grid_index(CoordTypes... coords);

        size_type& operator()(size_type dim) { return coords_[dim]; }
        const size_type& operator()(size_type dim) const { return coords_[dim]; }

        bool operator<(const grid_index& rhs) const {
            for (int i = 0; i < N; ++i) {
                if (coords_[i] < rhs.coords_[i]) {
                    return true;
                }
                else if (coords_[i] == rhs.coords_[i]) {
                    // continue on
                }
                else {
                    return false;
                }
            }

            return false; // equal
        }

    private:

        size_type coords_[N];

        template <size_type DIM, typename SizeType, typename... SizeTypes>
        void set_coords(SizeType size, SizeTypes... sizes)
        {
            static_assert(DIM < N-1, "Invalid dimension passed to set_coords");
            coords_[DIM] = size;
            this->set_coords<DIM+1>(sizes...);
        }

        template <size_type DIM, typename SizeType>
        void set_coords(SizeType size)
        {
            static_assert(DIM == N-1, "Invalid number of sizes passed to set_coords");
            coords_[N-1] = size;
        }

        void assign_all(size_type coord);
    };

    class grid_iterator : public std::iterator<
            std::bidirectional_iterator_tag,
            typename grid<N, T>::value_type>
    {
        friend class grid;

    public:

        typedef typename grid<N, T>::size_type size_type;
        typedef typename grid<N, T>::value_type value_type;

        grid_iterator();

        grid_iterator(const grid_iterator& other);
        grid_iterator& operator=(const grid_iterator& rhs);

        /// \name Iterator API
        ///@{
        grid_iterator& operator++();
        grid_iterator operator++(int);

        bool operator==(const grid_iterator& other) const;
        bool operator!=(const grid_iterator& other) const;

        value_type& operator*();
        value_type* operator->();

        grid_iterator& operator--();
        grid_iterator operator--(int);
        ///@}

        size_type coord(size_type dim) const { return curr_(dim); }

    private:

        grid<N, T>* grid_;
        grid_index begin_;
        grid_index end_;
        grid_index curr_;

        size_type size(size_type dim) const { return end_(dim) - begin_(dim) + 1; }
    };

private:

    value_type* data_;
    size_type   dims_[N];

    void copy(const grid& other);

    template <size_type DIM, typename SizeType, typename... SizeTypes> // TODO: how to declare DIM in a separate implementation?
    void set_sizes(SizeType size, SizeTypes... sizes)
    {
        static_assert(DIM < N-1, "Invalid dimension passed to set_sizes");
        dims_[DIM] = size;
        this->set_sizes<DIM+1>(sizes...);
    }

    template <size_type DIM, typename SizeType>
    void set_sizes(SizeType size)
    {
        static_assert(DIM == N-1, "Invalid number of sizes passed to set_sizes");
        dims_[N-1] = size;
    }

    size_type coord_to_index(const grid_index& index);

    template <typename... CoordTypes>
    size_type coord_to_index(CoordTypes... coords);

    template <int DIM, typename... CoordTypes, typename Coord>
    size_type coord_to_index_rec(size_type& agg, Coord coord, CoordTypes... coords);

    template <int DIM, typename Coord>
    size_type coord_to_index_rec(size_type& agg, Coord coord);

    template <int DIM>
    void assign_sizes(grid_index& index);

    template <int DIM, typename Coord, typename... CoordTypes>
    bool within_bounds(Coord coord, CoordTypes... coords) const;

    template <int DIM, typename Coord>
    bool within_bounds(Coord coord) const;

    grid_index create_last_index() const;
};

} // namespace au

#endif

#include "detail/grid.h"
