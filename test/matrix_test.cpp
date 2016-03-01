#include <spellbook/matrix/matrix.h>

int main(int argc, char* argv[])
{
    double M_d[] =
    {
        // 1.0, 2.0, 1.0,
        // 2.0, 6.0, 1.0,
        // 1.0, 1.0, 4.0
        2.0, 6.0, 1.0,
        0.0, 2.0, 1.0,
        1.0, 1.0, 4.0
    };

    au::matrix3d A(M_d);

    double b_d[] = { 7.0, 2.0, 3.0 };
    au::vector3d b(b_d);

    au::vector3d x = au::linsolve(A, b);

    return 0;
}
