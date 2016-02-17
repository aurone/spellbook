#ifndef au_vec4_h
#define au_vec4_h

namespace au {

template <typename T>
struct vec4
{
    T w, x, y, z;

    vec4() : w(), x(), y(), z() { }
    vec4(T w, T x, T y, T z) : w(w), x(x), y(y), z(z) { }
};

typedef vec4<float> vec4f;
typedef vec4<double> vec4d;
typedef vec4<long double> vec4ld;

} // namespace au

#endif
