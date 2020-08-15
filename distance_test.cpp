#include <calculator.hpp>
#include <iostream>

int main(int argc, char const* argv[])
{
    WGS84::LatLon ll, ll2; // populate from GPS receiver
    ll.Lon = -(1.0 + 4 / 60.0);
    ll.Lat = 53.0;

    ll2.Lon = -(1.0 + 4 / 60.0);
    ll2.Lat = (53.0 + 1 / 60.0);

    WGS84::ECEF ecef = WGS84::to_ECEF(ll);
    WGS84::ECEF ecef2 = WGS84::to_ECEF(ll2);

    double dist = distance(ecef, ecef2);

    OSGB36::ECEF os_ecef = helmert_transform(ecef);
    OSGB36::LatLon os_ll = olsons_algorithm(os_ecef);
    auto s = OSGB36::transverse_mercator(os_ll);

    OSGB36::ECEF os_ecef2 = helmert_transform(ecef2);
    OSGB36::LatLon os_ll2 = olsons_algorithm(os_ecef2);
    auto s2 = OSGB36::transverse_mercator(os_ll2);

    double cartesian_dist = sqrt(pow(s.Easting - s2.Easting, 2) + pow(s.Northing - s2.Northing, 2));

    std::cout.precision(10);
    std::cout << "Distance between the two points (GPS): " << std::fixed
              << dist / 1000 << "km" << std::endl;
    std::cout << "Distance between the two points (OS): " << std::fixed
              << cartesian_dist / 1000 << "km" << std::endl;
    std::cout << "Difference: " << std::scientific << dist - cartesian_dist
              << std::endl;
    return 0;
}
