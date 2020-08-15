#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP
#include <objects.hpp>

double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);
double seconds_to_radians(double seconds);
double sign(double x);
double operator*(WGS84::ECEF&, WGS84::ECEF&);
double operator*(OSGB36::ECEF&, OSGB36::ECEF&);

namespace OSGB36 {
double compute_meridan_arc(double dLat, double sLat, double n, double b);

NorthingEasting transverse_mercator(LatLon Coord);
string_t grid_ref(NorthingEasting NE);
OSGB36::LatLon olsons_algorithm(OSGB36::ECEF);
}

namespace WGS84 {
ECEF to_ECEF(LatLon);
string_t pluscode(LatLon);
WGS84::LatLon olsons_algorithm(WGS84::ECEF);
}

OSGB36::ECEF helmert_transform(WGS84::ECEF);

double distance(WGS84::ECEF, WGS84::ECEF);

#endif