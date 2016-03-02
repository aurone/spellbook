#ifndef au_matrix_h
#define au_matrix_h

// standard includes
#include <stdlib.h>
#include <initializer_list>
#include <ostream>
#include <stdexcept>

namespace au {

typedef size_t matrix_index;

template <typename T, matrix_index M, matrix_index N>
class matrix
{
public:

    typedef T value_type;
    typedef size_t size_type;

    static const matrix_index row_count = M;
    static const matrix_index col_count = N;

    static matrix identity();
    static matrix zeros();
    static matrix ones();

    matrix();

    template <typename U>
    matrix(std::initializer_list<U> init);

    template <typename InputIt>
    matrix(InputIt first, InputIt last);

    // assignment operators
    template <typename U> matrix& operator+=(U c);
    template <typename U> matrix& operator+=(const matrix<U, M, N>& rhs);
    template <typename U> matrix& operator-=(U c);
    template <typename U> matrix& operator-=(const matrix<U, M, N>& rhs);
    template <typename U> matrix& operator*=(U c);
    template <typename U> matrix& operator*=(const matrix<U, N, N>& rhs);
    template <typename U> matrix& operator/=(U c);

    T& operator()(matrix_index i, matrix_index j);
    const T& operator()(matrix_index i, matrix_index j) const;

    T& operator[](matrix_index i);
    const T& operator[](matrix_index i) const;

    const T* data() const;
    T* data();

private:

    T m_data[M * N];
};

//////////////////////////
// arithmetic operators //
//////////////////////////

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N> operator+(const matrix<T, M, N>& a);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N> operator-(const matrix<T, M, N>& a);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N> operator+(const matrix<T, M, N>& a, const matrix<T, M, N>& b);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N> operator-(const matrix<T, M, N>& a, const matrix<T, M, N>& b);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N> operator*(T c, const matrix<T, M, N>& m);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N> operator*(const matrix<T, M, N>& m, T c);

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N> operator/(const matrix<T, M, N>& m, T c);

template <typename T, matrix_index M, matrix_index N, matrix_index K>
matrix<T, M, K> operator*(const matrix<T, M, N>& a, const matrix<T, N, K>& b);

template <typename T, matrix_index M, matrix_index N>
matrix<T, N, M> transpose(const matrix<T, M, N>& m);

template <typename T, matrix_index M, matrix_index N>
matrix<T, N, M> inverse(const matrix<T, M, N>& m);

template <typename T, matrix_index N>
matrix<T, N, 1> linsolve(const matrix<T, N, N>& A, const matrix<T, N, 1>& b);

template <typename T, matrix_index M, matrix_index N>
std::ostream& operator<<(std::ostream& o, const matrix<T, M, N>& m);

template <typename T> using matrix1 = matrix<T, 1, 1>;
template <typename T> using matrix2 = matrix<T, 2, 2>;
template <typename T> using matrix3 = matrix<T, 3, 3>;
template <typename T> using matrix4 = matrix<T, 4, 4>;
template <typename T> using vector1 = matrix<T, 1, 1>;
template <typename T> using vector2 = matrix<T, 2, 1>;
template <typename T> using vector3 = matrix<T, 3, 1>;
template <typename T> using vector4 = matrix<T, 4, 1>;

typedef matrix1<float> matrix1f;
typedef matrix2<float> matrix2f;
typedef matrix3<float> matrix3f;
typedef matrix4<float> matrix4f;

typedef matrix1<double> matrix1d;
typedef matrix2<double> matrix2d;
typedef matrix3<double> matrix3d;
typedef matrix4<double> matrix4d;

typedef matrix1<long double> matrix1ld;
typedef matrix2<long double> matrix2ld;
typedef matrix3<long double> matrix3ld;
typedef matrix4<long double> matrix4ld;

typedef vector1<float> vector1f;
typedef vector2<float> vector2f;
typedef vector3<float> vector3f;
typedef vector4<float> vector4f;

typedef vector1<double> vector1d;
typedef vector2<double> vector2d;
typedef vector3<double> vector3d;
typedef vector4<double> vector4d;

typedef vector1<long double> vector1ld;
typedef vector2<long double> vector2ld;
typedef vector3<long double> vector3ld;
typedef vector4<long double> vector4ld;

struct matrix_exception : public std::logic_error
{
    explicit matrix_exception(const std::string& what_arg);
    explicit matrix_exception(const char* what_arg);
};

} // namespace au

#include "detail/matrix.h"

#endif
