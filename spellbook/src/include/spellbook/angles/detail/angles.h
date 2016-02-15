#ifndef au_detail_angles_h
#define au_detail_angles_h

#include <algorithm>
#include <math.h>

namespace au {

inline
double normalize_angle(
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
double shortest_angle_dist(double a1_rad, double a2_rad)
{
    double a1_norm = normalize_angle(a1_rad, 0.0, 2.0 * M_PI);
    double a2_norm = normalize_angle(a2_rad, 0.0, 2.0 * M_PI);
    return std::min(fabs(a1_norm - a2_norm), 2.0 * M_PI - fabs(a2_norm - a1_norm));
}

inline
double shortest_angle_diff(double a1_rad, double a2_rad)
{
    double a1_norm = normalize_angle(a1_rad, 0.0, 2.0 * M_PI);
    double a2_norm = normalize_angle(a2_rad, 0.0, 2.0 * M_PI);

    double dist = shortest_angle_dist(a1_rad, a2_rad);
    if (shortest_angle_dist(a1_norm + dist, a2_norm) < shortest_angle_dist(a1_norm - dist, a2_norm)) {
        return -dist;
    }
    else {
        return dist;
    }
}

inline
double to_radians(double angle_degs)
{
    // TODO: precompute these conversion constants via constexpr functions or
    // something similar with minimal namespace pollution
    return angle_degs * M_PI / 180.0;
}

inline
double to_degrees(double angle_rads)
{
    return angle_rads * 180.0 / M_PI;
}

} // namespace au

#endif
