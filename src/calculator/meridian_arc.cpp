#include <calculator.hpp>

double OSGB36::compute_meridan_arc(double dLat, double sLat, double n, double b)
{
    double M; // compute Meridian arc (eqn 8.1 [1])
    M = ((1 + n + ((5 * n * n) / 4) + ((5 * n * n * n) / 4)) * dLat) - (((3 * n) + (3 * n * n) + ((21 * n * n * n) / 8)) * sin(dLat) * cos(sLat)) + ((((15 * n * n) / 8) + ((15 * n * n * n) / 8)) * sin(2 * dLat) * cos(2 * sLat)) - (((35 * n * n * n) / 24) * sin(3 * dLat) * cos(3 * sLat));

    M *= b;

    return M;
}