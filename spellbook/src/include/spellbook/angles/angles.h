#ifndef au_angles_h
#define au_angles_h

namespace au {

double normalize_angle(
    double angle_rad,
    double angle_min_rad,
    double angle_max_rad);

double shortest_angle_dist(double a1_rad, double a2_rad);

double shortest_angle_diff(double a1_rad, double a2_rad);

double to_radians(double angle_degs);
double to_degrees(double angle_rads);

} // namespace au

#include "detail/angles.h"

#endif
