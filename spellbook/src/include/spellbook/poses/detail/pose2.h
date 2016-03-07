#ifndef au_detail_pose2_h
#define au_detail_pose2_h

#include <spellbook/angles/angles.h>
#include <spellbook/math/math.h>

namespace au {

template <typename T>
pose2<T>::pose2() :
    pos(),
    yaw()
{
}

template <typename T>
pose2<T>::pose2(T x, T y, T yaw) :
    pos(x, y),
    yaw(yaw)
{
}

template <typename T>
pose2<T>::pose2(const vec2<T>& pos, T yaw) :
    pos(pos),
    yaw(yaw)
{
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const pose2<T>& p)
{
    o << "(" << p.pos.x << ", " << p.pos.y << ", " << p.yaw << ")";
    return o;
}

template <typename T>
pose2<T> interp(const pose2<T>& p, const pose2<T>& q, T t)
{
    const double af = p.yaw + t * shortest_angle_diff(q.yaw, p.yaw);
    const double iang = normalize_angle(af, 0, 2.0 * M_PI);
    return pose2<T>(interp(p.pos, q.pos, t), iang);
}

} // namespace au

#endif
