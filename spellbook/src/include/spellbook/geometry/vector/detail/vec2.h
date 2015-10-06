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

template <typename T, typename U>
vec2<T> operator*(U c, const vec2<T>& v)
{
    return vec2<T>(c * v.x, c * v.y);
}

template <typename T, typename U>
vec2<T> operator*(const vec2<T>& v, U c)
{
    return vec2<T>(v.x * c, v.y * c);
}

template <typename T, typename U>
vec2<T> operator/(const vec2<T>& v, U c)
{
    return vec2<T>(v.x / c, v.y / c);
}

template <typename T>
T length(const vec2<T>& v)
{
    return sqrt(length_sqrd(v));
}

template <typename T>
T length_sqrd(const vec2<T>& v)
{
    return v.x * v.x + v.y * v.y;
}

template <typename T>
T dot(const vec2<T>& u, const vec2<T>& v)
{
    return u.x * v.x + u.y * v.y;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const vec2<T>& v)
{
    o << "(" << v.x << ", " << v.y << ")";
    return o;
}

} // namespace au

#endif
