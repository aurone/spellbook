#ifndef au_quaternion_h
#define au_quaternion_h

// standard includes
#include <ostream>

// project includes
#include <spellbook/geometry/vector/vec3.h>

namespace au {

template <typename T>
struct axis_angle;

template <typename T>
struct quaternion
{
    T w, x, y, z;

    quaternion();
    quaternion(T w, T x, T y, T z);
    quaternion(const axis_angle<T>& aa);
};

template <typename T>
quaternion<T> operator+(const quaternion<T>& p, const quaternion<T>& q);

template <typename T, typename U>
quaternion<T> operator*(U w, const quaternion<T>& q);

template <typename T, typename U>
quaternion<T> operator*(const quaternion<T>& q, U w);

template <typename T, typename U>
quaternion<T> operator/(const quaternion<T>& q, U w);

template <typename T>
quaternion<T> operator*(const quaternion<T>& p, const quaternion<T>& q);

template <typename T>
quaternion<T> conj(const quaternion<T>& q);

template <typename T>
quaternion<T> inv(const quaternion<T>& q);

template <typename T>
T length(const quaternion<T>& q);

template <typename T>
T length_sqrd(const quaternion<T>& q);

template <typename T>
std::ostream& operator<<(std::ostream& o, const quaternion<T>& q);

typedef quaternion<float> quaternionf;
typedef quaternion<double> quaterniond;
typedef quaternion<long double> quaternionld;

} // namespace au

#include "detail/quaternion.h"

#endif
