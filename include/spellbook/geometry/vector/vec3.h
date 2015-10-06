#ifndef au_vec3_h
#define au_vec3_h

namespace au {

template <typename T>
struct vec3
{
    T x, y, z;

    vec3() : x(), y(), z() { }
    vec3(T x, T y, T z) : x(x), y(y), z(z) { }
};

template <typename T>
vec3<T> operator+(const vec3<T>& u, const vec3<T>& v);

template <typename T>
vec3<T> operator-(const vec3<T>& u, const vec3<T>& v);

template <typename T>
vec3<T> operator*(T c, const vec3<T>& v);

template <typename T>
vec3<T> operator*(const vec3<T>& v, T c);

template <typename T>
vec3<T> operator/(const vec3<T>& v, T c);

template <typename T>
T length(const vec3<T>& v);

template <typename T>
T dot(const vec3<T>& u, const vec3<T>& v);

template <typename T>
vec3<T> cross(const vec3<T>& u, const vec3<T>& v);

typedef vec3<float> vec3f;
typedef vec3<double> vec3d;
typedef vec3<long double> vec3ld;

} // namespace au

#endif
