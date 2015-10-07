// standard includes
#include <math.h>
#include <iostream>
#include <random>

// system includes
#include <Eigen/Dense>
#include <spellbook/geometry/vector/vec2.h>
#include <spellbook/geometry/vector/vec3.h>
#include <spellbook/geometry/rotations/quaternion.h>
#include <spellbook/geometry/rotations/axis_angle.h>
#include <spellbook/matrix/matrix.h>

void TestVec2()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "| TestVec2" << std::endl;
    std::cout << "----------------------" << std::endl;

    au::vec2d u(3.0, 4.0);
    au::vec2d v(5.0, 8.0);

    std::cout << "u = " << u << std::endl;
    std::cout << "v = " << v << std::endl;
    std::cout << "u + v = " << u + v << std::endl;
    std::cout << "u - v = " << u - v << std::endl;
    std::cout << "3 * u = " << 3 * u << std::endl;
    std::cout << "u * 3 = " << u * 3 << std::endl;
    std::cout << "u / 3 = " << u / 3 << std::endl;
    std::cout << "length(u) = " << length(u) << std::endl;
    std::cout << "dot(u, v) = " << dot(u, v) << std::endl;
}

void TestVec3()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "| TestVec3" << std::endl;
    std::cout << "----------------------" << std::endl;

    au::vec3d u(3.0, 4.0, 5.0);
    au::vec3d v(5.0, 8.0, 6.0);

    std::cout << "u = " << u << std::endl;
    std::cout << "v = " << v << std::endl;
    std::cout << "u + v = " << u + v << std::endl;
    std::cout << "u - v = " << u - v << std::endl;
    std::cout << "3 * u = " << 3 * u << std::endl;
    std::cout << "u * 3 = " << u * 3 << std::endl;
    std::cout << "u / 3 = " << u / 3 << std::endl;
    std::cout << "length(u) = " << length(u) << std::endl;
    std::cout << "dot(u, v) = " << dot(u, v) << std::endl;
    std::cout << "cross(u, v) = " << cross(u, v) << std::endl;

    std::cout << dot(u, cross(u, v)) << std::endl;
    std::cout << dot(v, cross(u, v)) << std::endl;
}

void TestQuaternion()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "| TestQuaternion" << std::endl;
    std::cout << "----------------------" << std::endl;

    const double angle = M_PI / 4.0;
    const au::vec3d axis(0.0, 0.0, 1.0);

    au::quaterniond q1(au::axis_angled(angle, axis));
    au::quaterniond q2(au::axis_angled(-angle, axis));

    std::cout << "q1 = " << q1 << std::endl;
    std::cout << "q2 = " << q2 << std::endl;
    std::cout << "q1 + q2 = " << q1 + q2 << std::endl;
    std::cout << "2 * q1 = " << 2 * q1 << std::endl;
    std::cout << "q1 * 2 = " << q1 * 2 << std::endl;
    std::cout << "q1 / 2 = " << q1 / 2 << std::endl;
    std::cout << "q1 * q2 = " << q1 * q2 << std::endl;
    std::cout << "conj(q1) = " << conj(q1) << std::endl;
    std::cout << "conj(q2) = " << conj(q2) << std::endl;
    std::cout << "inv(q1) = " << inv(q1) << std::endl;
    std::cout << "inv(q2) = " << inv(q2) << std::endl;
    std::cout << "length(q1) = " << length(q1) << std::endl;
    std::cout << "length(q2) = " << length(q2) << std::endl;

    au::quaterniond x(0.0, 1.0, 0.0, 0.0);
    std::cout << "q1xq1* = " << q1 * x * conj(q1) << std::endl;

    au::axis_angled aa(M_PI / 4.0, 0.0, 0.0, 1.0);
    std::cout << "aa = " << aa << std::endl;
    std::cout << "(quaternion)aa = " << au::quaterniond(aa) << std::endl;

    {
        std::cout << au::quaterniond(au::axis_angled(0.0, au::vec3d(1.0, 0.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled( M_PI,  au::vec3d(1.0, 0.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled(-M_PI, -au::vec3d(1.0, 0.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled( M_PI,  au::vec3d(0.0, 1.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled(-M_PI, -au::vec3d(0.0, 1.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled( M_PI,  au::vec3d(0.0, 0.0, 1.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled(-M_PI, -au::vec3d(0.0, 0.0, 1.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled( 0.5 * M_PI,  au::vec3d(1.0, 0.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled(-0.5 * M_PI, -au::vec3d(1.0, 0.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled( 0.5 * M_PI,  au::vec3d(0.0, 1.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled(-0.5 * M_PI, -au::vec3d(0.0, 1.0, 0.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled( 0.5 * M_PI,  au::vec3d(0.0, 0.0, 1.0))) << std::endl;
        std::cout << au::quaterniond(au::axis_angled(-0.5 * M_PI, -au::vec3d(0.0, 0.0, 1.0))) << std::endl;
    }

//    Eigen::Vector3d v; v << 1.0, 0.0, 0.0;
//
//    Eigen::AngleAxisd aa(M_PI / 4.0, Eigen::Vector3d(0.0, 0.0, 1.0));
//    Eigen::Quaterniond eq;
//    eq = aa;
//
//    std::cout << eq * v << std::endl;
}

void TestMatrix()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "| TestMatrix" << std::endl;
    std::cout << "----------------------" << std::endl;

    std::vector<double> ints(9);
    for (int i = 0; i < 9; ++i) {
        ints[i] = (double)i;
    }

    std::vector<double> bints = ints;
    std::reverse(bints.begin(), bints.end());

    au::matrix3d a(ints.data());
    std::cout << "a = " << a << std::endl;

    au::matrix3d b(bints.data());
    std::cout << "b = " << b << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a^T = " << transpose(a) << std::endl;
}

int main(int argc, char *argv[])
{
    TestVec2();
    TestVec3();
    TestQuaternion();
    TestMatrix();
    return 0;
}
