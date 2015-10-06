#ifndef au_detail_vec3_h
#define au_detail_vec3_h

namespace au {

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

} // namespace au

#endif
