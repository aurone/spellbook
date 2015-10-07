#ifndef au_detail_matrix_h
#define au_detail_matrix_h

#include <string.h>

namespace au {

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>::matrix() : m_data() { }

template <typename T, matrix_index M, matrix_index N>
matrix<T, M, N>::matrix(T* _data) : m_data()
{
    memcpy(m_data, _data, sizeof(T) * M * N);
}

template <typename T, matrix_index M, matrix_index N>
T& matrix<T, M, N>::operator()(matrix_index i, matrix_index j)
{
    return m_data[i * M + j];
}

template <typename T, matrix_index M, matrix_index N>
const T& matrix<T, M, N>::operator()(matrix_index i, matrix_index j) const
{
    return m_data[i * M + j];
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
    }
    o << "]";
    return o;
}

} // namespace au

#endif
