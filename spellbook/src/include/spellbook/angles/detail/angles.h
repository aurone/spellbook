#ifndef au_detail_angles_h
#define au_detail_angles_h

#include <algorithm>
#include <math.h>

namespace au {

inline
double NormalizeAngle(
    double angle_rad,
    double angle_min_rad,
    double angle_max_rad)
{
    if (fabs(angle_rad) > 2.0 * M_PI) { // normalize to [-2*pi, 2*pi] range
        angle_rad = fmod(angle_rad, 2.0 * M_PI);
    }

    while (angle_rad > angle_max_rad) {
        angle_rad -= 2.0 * M_PI;
    }

    while (angle_rad < angle_min_rad) {
        angle_rad += 2.0 * M_PI;
    }

    return angle_rad;
}

inline
double ShortestAngleDist(double a1_rad, double a2_rad)
{
    double a1_norm = NormalizeAngle(a1_rad, 0.0, 2.0 * M_PI);
    double a2_norm = NormalizeAngle(a2_rad, 0.0, 2.0 * M_PI);
    return std::min(fabs(a1_norm - a2_norm), 2.0 * M_PI - fabs(a2_norm - a1_norm));
}

inline
double ShortestAngleDiff(double a1_rad, double a2_rad)
{
    double a1_norm = NormalizeAngle(a1_rad, 0.0, 2.0 * M_PI);
    double a2_norm = NormalizeAngle(a2_rad, 0.0, 2.0 * M_PI);

    double dist = ShortestAngleDist(a1_rad, a2_rad);
    if (ShortestAngleDist(a1_norm + dist, a2_norm) < ShortestAngleDist(a1_norm - dist, a2_norm)) {
        return -dist;
    }
    else {
        return dist;
    }
}

} // namespace au

#endif
