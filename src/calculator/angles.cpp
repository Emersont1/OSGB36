#include <calculator.hpp>

double OSGB36::degrees_to_radians(double degrees)
{
    return (degrees * M_PI) / 180;
}

double OSGB36::radians_to_degrees(double radians)
{
    return (radians * 180) / M_PI;
}

double OSGB36::seconds_to_radians(double seconds)
{
    return OSGB36::degrees_to_radians(seconds / 3600);
}

double OSGB36::sign(double x)
{
    if (x > 0)
        return 1;
    if (x < 0)
        return -1;
    return 0;
}