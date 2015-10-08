#ifndef au_angles_h
#define au_angles_h

namespace au {

double NormalizeAngle(
    double angle_rad,
    double angle_min_rad,
    double angle_max_rad);

double ShortestAngleDist(double a1_rad, double a2_rad);

double ShortestAngleDiff(double a1_rad, double a2_rad);

} // namespace au

#include "detail/angles.h"

#endif
