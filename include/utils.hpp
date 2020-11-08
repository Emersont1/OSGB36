#ifndef UTILS_HPP
#define UTILS_HPP

inline double degrees_to_radians(double degrees)
{
    return (degrees * M_PI) / 180;
}

inline double radians_to_degrees(double radians)
{
    return (radians * 180) / M_PI;
}

inline double seconds_to_radians(double seconds)
{
    return degrees_to_radians(seconds / 3600);
}

inline double sign(double x)
{
    if (x > 0)
        return 1;
    if (x < 0)
        return -1;
    return 0;
}
#endif