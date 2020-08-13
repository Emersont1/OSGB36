#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP
#include <objects.hpp>

namespace OSGB36 {
double compute_meridan_arc(double dLat, double sLat, double n, double b);
double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);
double seconds_to_radians(double seconds);
double sign(double x);

NorthingEasting transverse_mercator(LatLon Coord);
string_t grid_ref(NorthingEasting NE);
}

OSGB36::LatLon geoid_convert(WGS84::LatLon);
OSGB36::LatLon olsons_algorithm(double& x, double& y, double& z);


#endif