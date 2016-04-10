#ifndef au_constants_h
#define au_constants_h

namespace au {

template <typename T>
class constants
{
public:
};

template <>
class constants<double>
{
public:

    static double pi() { return 3.141592653589793238462643383275028841; }
};

template <>
class constants<float>
{
public:

    static float pi() { return 3.141592653589793238462643383275028841F; }
};

template <>
class constants<long double>
{
public:

    static long double pi() { return 3.141592653589793238462643383275028841l; }
};

} // namespace au

#endif
