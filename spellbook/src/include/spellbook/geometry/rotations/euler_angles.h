#ifndef au_euler_angles_h
#define au_euler_angles_h

namespace au {

enum class angle_convention
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
}

template <typename T, int AngleConvention = angle_convention::ZYZ>
struct euler_angles
{
    T alpha, beta, gamma;
};

} // namespace au

#endif
