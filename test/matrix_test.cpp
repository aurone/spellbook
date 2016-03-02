#define BOOST_TEST_MODULE MatrixTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <spellbook/matrix/matrix.h>

BOOST_AUTO_TEST_CASE(MatrixConstructionTest)
{
    au::matrix3d A = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
    BOOST_CHECK_EQUAL(A(0,0), 1.0);
    BOOST_CHECK_EQUAL(A(0,1), 2.0);
    BOOST_CHECK_EQUAL(A(0,2), 3.0);
    BOOST_CHECK_EQUAL(A(1,0), 4.0);
    BOOST_CHECK_EQUAL(A(1,1), 5.0);
    BOOST_CHECK_EQUAL(A(1,2), 6.0);
    BOOST_CHECK_EQUAL(A(2,0), 7.0);
    BOOST_CHECK_EQUAL(A(2,1), 8.0);
    BOOST_CHECK_EQUAL(A(2,2), 9.0);

    double C_d[9] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
    au::matrix3d C(C_d, C_d + 9);
    BOOST_CHECK_EQUAL(C(0,0), 1.0);
    BOOST_CHECK_EQUAL(C(0,1), 2.0);
    BOOST_CHECK_EQUAL(C(0,2), 3.0);
    BOOST_CHECK_EQUAL(C(1,0), 4.0);
    BOOST_CHECK_EQUAL(C(1,1), 5.0);
    BOOST_CHECK_EQUAL(C(1,2), 6.0);
    BOOST_CHECK_EQUAL(C(2,0), 7.0);
    BOOST_CHECK_EQUAL(C(2,1), 8.0);
    BOOST_CHECK_EQUAL(C(2,2), 9.0);
}

BOOST_AUTO_TEST_CASE(IdentityMatrixTest)
{

}

BOOST_AUTO_TEST_CASE(AdditionTest)
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

    au::matrix3d A(M_d, M_d + 9);

    double b_d[] = { 7.0, 2.0, 3.0 };
    au::vector3d b(b_d, b_d + 3);

    au::vector3d x = au::linsolve(A, b);
}

BOOST_AUTO_TEST_CASE(NegationTest)
{

}

BOOST_AUTO_TEST_CASE(MultiplicationTest)
{

}

BOOST_AUTO_TEST_CASE(TransposeTest)
{

}

BOOST_AUTO_TEST_CASE(InverseTest)
{

}

BOOST_AUTO_TEST_CASE(LinsolveTest)
{
    au::matrix3d A = { 2, 6, 1, 0, 2, 1, 1, 1, 4 };
    au::vector3d b = { 7, 2, 3 };
    au::vector3d x = au::linsolve(A, b);
    std::cout << x << std::endl;
}
