#ifndef au_euler_angles_h
#define au_euler_angles_h

namespace au {

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

template <typename T, int AngleConvention = angle_convention::ZYZ>
struct euler_angles
{
    T alpha, beta, gamma;

    euler_angles() : alpha(), beta(), gamma() { }
    
    euler_angles(T alpha, T beta, T gamma) :
        alpha(alpha), beta(beta), gamma(gamma) { }
};

} // namespace au

#endif
