#include <calculator.hpp>
#include <iostream>

double distance(WGS84::ECEF a, WGS84::ECEF b)
{
    double mod_a = sqrt(a * a);
    double mod_b = sqrt(b * b);

    double cos_theta = (a * b) / (mod_a * mod_b);
    double theta = acos(cos_theta); // RADIANS!

    double distance = (mod_b + mod_a) * theta / 2;

    return distance;
}