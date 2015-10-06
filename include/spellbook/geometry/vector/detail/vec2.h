#ifndef au_detail_vec2_h
#define au_detail_vec2_h

#include <math.h>

namespace au {

template <typename T>
vec2<T> operator+(const vec2<T>& u, const vec2<T>& v)
{
    return vec2<T>(u.x + v.x, u.y + v.y);
}

template <typename T>
vec2<T> operator-(const vec2<T>& u, const vec2<T>& v)
{
    return vec2<T>(u.x - v.x, u.y - v.y);
}

template <typename T>
vec2<T> operator*(T c, const vec2<T>& v)
{
    return vec2<T>(v.x * c, v.y * c);
}

template <typename T>
vec2<T> operator*(const vec2<T>& v, T c)
{
    return c * v;
}

template <typename T>
vec2<T> operator/(const vec2<T>& v, T c)
{
    return v * ((T)1 / c);
}

template <typename T>
T length(const vec2<T>& v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
T dot(const vec2<T>& u, const vec2<T>& v)
{
    return u.x * v.x + u.y * v.y;
}

} // namespace au

#endif
