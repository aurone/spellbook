#ifndef Quaternion_h
#define Quaternion_h

#include <math.h>

namespace au {

template <class T>
struct quaternion
{
    T w, x, y, z;

    quaternion() : w(), x(), y(), z() { }

    quaternion(T w, T x, T y, T, z) : w(w), x(x), y(y), z(z) { }
};

template <class T>
quaternion<T> operator+(const quaternion<T>& p, const quaternion<T>& q)
{
    return quaternion<T>(p.w + q.w, p.x + q.x, p.y + q.y, p.z + q.z);
}

template <class T>
quaternion<T> operator*(T w, const quaternion<T>& q)
{
    return quaternion<T>(w * q.w, w * q.x, w * q.y, w * q.z);
}

template <class T>
quaternion<T> operator*(const quaternion<T>& q, T w)
{
    return w * q;
}

template <class T>
quaternion<T> operator*(const quaternion<T>& p, const quaternion<T>& q)
{

}

template <class T>
quaternion<T> conjugate(const quaternion<T>& q)
{
    return quaternion<T>(q.w, -q.x, -q.y, -q.z);
}

template <class T>
T length(const quaternion<T>& q)
{
    return sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
}

} // namespace au

#endif
