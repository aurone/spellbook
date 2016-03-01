#ifndef au_detail_matrix_h
#define au_detail_matrix_h

#include <string.h>

namespace au {

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N> matrix<T, M, N>::Identity()
{
    matrix<T, M, N> m;
    memset(m.m_data, 0, M * N * sizeof(T));

    for (int i = 0; i < std::min(M, N); ++i) {
        m(i, i) = 1.0;
    }

    return m;
}

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>::matrix() : m_data() { }

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>::matrix(const T* _data) : m_data()
{
    memcpy(m_data, _data, sizeof(T) * M * N);
}

template <typename T, matrix_index M, matrix_index N>
T& matrix<T, M, N>::operator()(matrix_index i, matrix_index j)
{
    return m_data[i * N + j];
}

template <typename T, matrix_index M, matrix_index N>
const T& matrix<T, M, N>::operator()(matrix_index i, matrix_index j) const
{
    return m_data[i * N + j];
}

template <typename T, matrix_index M, matrix_index N>
T& matrix<T, M, N>::operator[](matrix_index i)
{
    return m_data[i];
}

template <typename T, matrix_index M, matrix_index N>
const T& matrix<T, M, N>::operator[](matrix_index i) const
{
    return m_data[i];
}

template <typename T, matrix_index M, matrix_index N>
const T* matrix<T, M, N>::data() const
{
    return m_data;
}

template <typename T, matrix_index M, matrix_index N>
T* matrix<T, M, N>::data()
{
    return m_data;
}

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator+(const matrix<T, M, N>& a, const matrix<T, M, N>& b)
{
    matrix<T, M, N> m;
    for (matrix_index i = 0; i < M; ++i) {
        for (matrix_index j = 0; j < N; ++j) {
            m(i, j) = a(i, j) + b(i, j);
        }
    }
    return m;
}

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator-(const matrix<T, M, N>& a, const matrix<T, M, N>& b)
{
    matrix<T, M, N> m;
    for (matrix_index i = 0; i < M; ++i) {
        for (matrix_index j = 0; j < N; ++j) {
            m(i, j) = a(i, j) - b(i, j);
        }
    }
    return m;
}

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator*(T c, const matrix<T, M, N>& m)
{
    matrix<T, M, N> out;
    for (matrix_index i = 0; i < M * N; ++i) {
        out[i] = c * m[i];
    }
    return out;
}

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator*(const matrix<T, M, N>& m, T c)
{
    matrix<T, M, N> out;
    for (matrix_index i = 0; i < M * N; ++i) {
        out[i] = m[i] * c;
    }
    return out;
}

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>
operator/(const matrix<T, M, N>& m, T c)
{
    matrix<T, M, N> out;
    for (matrix_index i = 0; i < M * N; ++i) {
        out[i] = m[i] / c;
    }
    return out;
}

template <typename T, matrix_index M, matrix_index N, matrix_index K>
matrix<T, M, K>
operator*(const matrix<T, M, N>& a, const matrix<T, N, K>& b)
{
    matrix<T, M, K> m;
    for (matrix_index i = 0; i < M; ++i) {
        for (matrix_index j = 0; j < K; ++j) {
            m(i, j) = (T)0;
            for (matrix_index k = 0; k < N; ++k) {
                m(i, j) += a(i, k) * b(k, j);
            }
        }
    }
    return m;
}

template <typename T, matrix_index M, matrix_index N>
matrix<T, N, M> transpose(const matrix<T, M, N>& m)
{
    matrix<T, N, M> out;
    for (matrix_index i = 0; i < M; ++i) {
        for (matrix_index j = 0; j < N; ++j) {
            out(j, i) = m(i, j);
        }
    }
    return out;
}

template <typename T, matrix_index M, matrix_index N>
matrix<T, N, M> inverse(const matrix<T, M, N>& m)
{
    // TODO: implement generic inverse computation
    matrix<T, N, M> out;
    return out;
}

template <typename T>
matrix2<T> inverse(const matrix2<T>& m)
{
    const T& a11 = m(0, 0);
    const T& a12 = m(0, 1);
    const T& a21 = m(1, 0);
    const T& a22 = m(1, 1);

    au::matrix2<T> Ainv;
    const T d = a11 * a22 - a12 * a21;

    // TODO: raise error if non-invertible
    const T dinv = 1.0 / d;
    Ainv(0, 0) = dinv * a22;
    Ainv(0, 1) = dinv * -a12;
    Ainv(1, 0) = dinv * -a21;
    Ainv(1, 1) = dinv * a11;
    return Ainv;
}

template <typename T>
matrix3<T> inverse(const matrix3<T>& m)
{
    const T& a11 = m(0, 0);
    const T& a12 = m(0, 1);
    const T& a13 = m(0, 2);
    const T& a21 = m(1, 0);
    const T& a22 = m(1, 1);
    const T& a23 = m(1, 2);
    const T& a31 = m(2, 0);
    const T& a32 = m(2, 1);
    const T& a33 = m(2, 2);

    const T d =
            a11 * (a22 * a33 - a32 * a23) -
            a12 * (a21 * a33 - a23 * a31) +
            a13 * (a21 * a32 - a22 * a31);

    // TODO: raise error if non-invertible
    const T dinv = 1.0 / d;
    const T ap11 = a22 * a33 - a23 * a32;
    const T ap12 = a13 * a32 - a12 * a33;
    const T ap13 = a12 * a23 - a13 * a22;
    const T ap21 = a23 * a31 - a21 * a33;
    const T ap22 = a11 * a33 - a13 * a31;
    const T ap23 = a13 * a21 - a11 * a23;
    const T ap31 = a21 * a32 - a22 * a31;
    const T ap32 = a12 * a31 - a11 * a32;
    const T ap33 = a11 * a22 - a12 * a21;

    au::matrix3<T> Ainv;
    Ainv(0, 0) = dinv * ap11;
    Ainv(0, 1) = dinv * ap12;
    Ainv(0, 2) = dinv * ap13;
    Ainv(1, 0) = dinv * ap21;
    Ainv(1, 1) = dinv * ap22;
    Ainv(1, 2) = dinv * ap23;
    Ainv(2, 0) = dinv * ap31;
    Ainv(2, 1) = dinv * ap32;
    Ainv(2, 2) = dinv * ap33;
    return Ainv;
}

template <typename T, matrix_index M, matrix_index N>
std::ostream& operator<<(std::ostream& o, const matrix<T, M, N>& m)
{
    o << "[ ";
    for (matrix_index i = 0; i < M; ++i) {
        for (matrix_index j = 0; j < N; ++j) {
            o << m(i, j);
            if (j != N - 1) {
                o << ", ";
            }
        }
        if (i != M - 1) {
            o << "; ";
        }
        else {
            o << " ";
        }
    }
    o << "]";
    return o;
}

matrix_exception::matrix_exception(const std::string& what_arg) :
    logic_error(what_arg)
{ }

matrix_exception::matrix_exception(const char* what_arg) :
    logic_error(what_arg)
{ }

} // namespace au

#endif
