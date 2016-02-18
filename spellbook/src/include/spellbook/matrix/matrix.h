#ifndef au_matrix_h
#define au_matrix_h

// standard includes
#include <stdlib.h>
#include <ostream>

namespace au {

typedef int matrix_index;

template <typename T, matrix_index M, matrix_index N>
class matrix
{
public:

    static const matrix_index NumRows = M;
    static const matrix_index NumCols = N;

    static matrix Identity();

    T m_data[M * N];

    matrix();
    matrix(const T* _data);

    T& operator()(matrix_index i, matrix_index j);
    const T& operator()(matrix_index i, matrix_index j) const;

    T& operator[](matrix_index i);
    const T& operator[](matrix_index i) const;

    const T* data() const;
    T* data();
};

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator+(const matrix<T, M, N>& a, const matrix<T, M, N>& b);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator-(const matrix<T, M, N>& a, const matrix<T, M, N>& b);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator*(T c, const matrix<T, M, N>& m);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator*(const matrix<T, M, N>& m, T c);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator/(const matrix<T, M, N>& m, T c);

template <typename T, matrix_index M, matrix_index N, matrix_index K>
matrix<T, M, K>
operator*(const matrix<T, M, N>& a, const matrix<T, N, K>& b);

template <typename T, matrix_index M, matrix_index N>
matrix<T, N, M> transpose(const matrix<T, M, N>& m);

template <typename T, matrix_index M, matrix_index N>
matrix<T, N, M> inverse(const matrix<T, M, N>& m);

template <typename T, matrix_index M, matrix_index N>
std::ostream& operator<<(std::ostream& o, const matrix<T, M, N>& m);

template <typename T> using matrix2 = matrix<T, 2, 2>;
template <typename T> using matrix3 = matrix<T, 3, 3>;
template <typename T> using matrix4 = matrix<T, 4, 4>;

typedef matrix<float, 1, 1> matrix1f;
typedef matrix<float, 2, 2> matrix2f;
typedef matrix<float, 3, 3> matrix3f;
typedef matrix<float, 4, 4> matrix4f;

typedef matrix<double, 1, 1> matrix1d;
typedef matrix<double, 2, 2> matrix2d;
typedef matrix<double, 3, 3> matrix3d;
typedef matrix<double, 4, 4> matrix4d;

typedef matrix<long double, 1, 1> matrix1ld;
typedef matrix<long double, 2, 2> matrix2ld;
typedef matrix<long double, 3, 3> matrix3ld;
typedef matrix<long double, 4, 4> matrix4ld;

} // namespace au

#include "detail/matrix.h"

#endif
