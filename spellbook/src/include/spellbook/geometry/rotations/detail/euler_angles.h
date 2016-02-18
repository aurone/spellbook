#ifndef au_detail_euler_angles_h
#define au_detail_euler_angles_h

namespace au {

template <typename T, int AngleConvention>
std::ostream& operator<<(
    std::ostream& o,
    const euler_angles<T, AngleConvention>& ea)
{
    o << "(" << ea.alpha << ", " << ea.beta << ", " << ea.gamma << ")";
    return o;
}

} // namespace au

#endif
