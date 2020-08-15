#include <calculator.hpp>

double degrees_to_radians(double degrees)
{
    return (degrees * M_PI) / 180;
}

double radians_to_degrees(double radians)
{
    return (radians * 180) / M_PI;
}

double seconds_to_radians(double seconds)
{
    return degrees_to_radians(seconds / 3600);
}

double sign(double x)
{
    if (x > 0)
        return 1;
    if (x < 0)
        return -1;
    return 0;
}

double operator*(WGS84::ECEF& l, WGS84::ECEF& r)
{
    return l.x * r.x + l.y * r.y + l.z * r.z;
}

double operator*(OSGB36::ECEF& l, OSGB36::ECEF& r)
{
    return l.x * r.x + l.y * r.y + l.z * r.z;
}