#ifndef au_detail_vec3_h
#define au_detail_vec3_h

#include <math.h>

namespace au {

template <typename T>
void vec3<T>::normalize()
{
    *this = *this / length();
}

template <typename T>
T vec3<T>::length() const
{
    return sqrt(length_sqrd());
}

template <typename T>
T vec3<T>::length_sqrd() const
{
    return x * x + y * y + z * z;
}

template <typename T>
T vec3<T>::norm() const
{
    return length();
}

template <typename T>
T vec3<T>::norm_sqrd() const
{
    return length_sqrd();
}

template <typename T>
vec3<T> vec3<T>::normalized() const
{
    return *this / norm();
}

template <typename T>
vec3<T> operator+(const vec3<T>& u, const vec3<T>& v)
{
    return vec3<T>(u.x + v.x, u.y + v.y, u.z + v.z);
}

template <typename T>
vec3<T> operator-(const vec3<T>& u, const vec3<T>& v)
{
    return vec3<T>(u.x - v.x, u.y - v.y, u.z - v.z);
}

template <typename T, typename U>
vec3<T> operator*(U c, const vec3<T>& v)
{
    return vec3<T>(c * v.x, c * v.y, c * v.z);
}

template <typename T, typename U>
vec3<T> operator*(const vec3<T>& v, U c)
{
    return vec3<T>(v.x * c, v.y * c, v.z * c);
}

template <typename T, typename U>
vec3<T> operator/(const vec3<T>& v, U c)
{
    return vec3<T>(v.x / c, v.y / c, v.z / c);
}

template <typename T>
T length(const vec3<T>& v)
{
    return sqrt(length_sqrd(v));
}

template <typename T>
T length_sqrd(const vec3<T>& v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

template <typename T>
T dot(const vec3<T>& u, const vec3<T>& v)
{
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

template <typename T>
vec3<T> cross(const vec3<T>& u, const vec3<T>& v)
{
    return vec3<T>(
            u.y * v.z - u.z * v.y,
            u.z * v.x - u.x * v.z,
            u.x * v.y - u.y * v.x);
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const vec3<T>& v)
{
    o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return o;
}

} // namespace au

#endif
