#ifndef au_detail_quaternion_h
#define au_detail_quaternion_h

// standard includes
#include <math.h>

// project includes
#include <spellbook/geometry/rotations/axis_angle.h>

namespace au {

template <typename T>
quaternion<T>::quaternion() :
    w(), x(), y(), z()
{
}

template <typename T>
quaternion<T>::quaternion(T w, T x, T y, T z) :
    w(w), x(x), y(y), z(z)
{
}

template <typename T>
quaternion<T>::quaternion(const axis_angle<T>& aa) :
    w(), x(), y(), z()
{
    w = cos(0.5 * aa.angle);
    vec3<T> v = sin(0.5 * aa.angle) * aa.axis;
    x = v.x;
    y = v.y;
    z = v.z;
}

template <typename T>
quaternion<T> operator+(const quaternion<T>& p, const quaternion<T>& q)
{
    return quaternion<T>(p.w + q.w, p.x + q.x, p.y + q.y, p.z + q.z);
}

template <typename T, typename U>
quaternion<T> operator*(U w, const quaternion<T>& q)
{
    return quaternion<T>(w * q.w, w * q.x, w * q.y, w * q.z);
}

template <typename T, typename U>
quaternion<T> operator*(const quaternion<T>& q, U w)
{
    return quaternion<T>(q.w * w, q.x * w, q.y * w, q.z * w);
}

template <typename T, typename U>
quaternion<T> operator/(const quaternion<T>& q, U w)
{
    return quaternion<T>(q.w / w, q.x / w, q.y / w, q.z / w);
}

template <typename T>
quaternion<T> operator*(const quaternion<T>& p, const quaternion<T>& q)
{
    const vec3<T> u(p.x, p.y, p.z);
    const vec3<T> v(q.x, q.y, q.z);

    const T w = p.w * q.w - dot(u, v);
    const vec3<T> t = p.w * v + q.w * u + cross(u, v);

    return quaternion<T>(w, t.x, t.y, t.z);
}

template <typename T>
quaternion<T> conj(const quaternion<T>& q)
{
    return quaternion<T>(q.w, -q.x, -q.y, -q.z);
}

template <typename T>
quaternion<T> inv(const quaternion<T>& q)
{
    return conj(q) / length_sqrd(q);
}

template <typename T>
T length(const quaternion<T>& q)
{
    return sqrt(length_sqrd(q));
}

template <typename T>
T length_sqrd(const quaternion<T>& q)
{
    return q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const quaternion<T>& q)
{
    o << "(" << q.w << ", " << q.x << ", " << q.y << ", " << q.z << ")";
    return o;
}

} // namespace au

#endif
