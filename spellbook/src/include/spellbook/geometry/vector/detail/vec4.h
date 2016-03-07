#ifndef au_detail_vec4_h
#define au_detail_vec4_h

namespace au {

template <typename T>
std::ostream& operator<<(std::ostream& o, const vec4<T>& v)
{
    o << "(" << v.w << ", " << v.x << ", " << v.y << ", " << v.z << ")";
    return o;
}

} // namespace au

#endif
