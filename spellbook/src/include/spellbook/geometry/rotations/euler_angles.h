#ifndef au_euler_angles_h
#define au_euler_angles_h

#include <ostream>

namespace au {

template <typename T>
class rotmat;

namespace angle_convention {
enum
{
    XYX = 0,
    XZX,
    YXY,
    YZY,
    ZXZ,
    ZYZ,
    XYZ,
    XZY,
    YXZ,
    YZX,
    ZXY,
    ZYX
};
} // namespace angle_convention

template <typename T, int AngleConvention>
struct euler_angles
{
    T alpha, beta, gamma;

    euler_angles() : alpha(), beta(), gamma() { }

    euler_angles(T alpha, T beta, T gamma) :
        alpha(alpha), beta(beta), gamma(gamma)
    { }

    euler_angles(const rotmat<T>& R);
};

template <typename T>
using xyx_angles = euler_angles<T, angle_convention::XYX>;
template <typename T>
using xzx_angles = euler_angles<T, angle_convention::XZX>;
template <typename T>
using yxy_angles = euler_angles<T, angle_convention::YXY>;
template <typename T>
using yzy_angles = euler_angles<T, angle_convention::YZY>;
template <typename T>
using zxz_angles = euler_angles<T, angle_convention::ZXZ>;
template <typename T>
using zyz_angles = euler_angles<T, angle_convention::ZYZ>;
template <typename T>
using xyz_angles = euler_angles<T, angle_convention::XYZ>;
template <typename T>
using xzy_angles = euler_angles<T, angle_convention::XZY>;
template <typename T>
using yxz_angles = euler_angles<T, angle_convention::YXZ>;
template <typename T>
using yzx_angles = euler_angles<T, angle_convention::YZX>;
template <typename T>
using zxy_angles = euler_angles<T, angle_convention::ZXY>;
template <typename T>
using zyx_angles = euler_angles<T, angle_convention::ZYX>;

template <typename T, int AngleConvention>
std::ostream& operator<<(std::ostream& o, const euler_angles<T, AngleConvention>& v);

} // namespace au

#include "detail/euler_angles.h"

#endif
