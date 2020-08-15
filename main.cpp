#include <iostream>

#include <calculator.hpp>

int main(int argc, char const* argv[])
{
    WGS84::LatLon ll; // populate from GPS receiver

    std::cin >> ll.Lat >> ll.Lon >> ll.Alt;

    WGS84::ECEF ecef = WGS84::to_ECEF(ll);
    OSGB36::ECEF ecef2 = helmert_transform(ecef);
    OSGB36::LatLon ll2 = olsons_algorithm(ecef2);

    std::cout.precision(10);
    std::cout << "WGS84 Lon/Lat/Alt:\t\t" << std::fixed << ll.Lat << " "
              << std::fixed << ll.Lon << " " << std::fixed << ll.Alt << std::endl;
    std::cout << "OSGB36 Lon/Lat/Alt:\t\t" << std::fixed << ll2.Lat << " "
              << std::fixed << ll2.Lon << " " << std::fixed << ll2.Alt
              << std::endl;

    auto s = OSGB36::transverse_mercator(ll2);

    std::cout << "OSGB36 Northing & Easting:\t" << (int)s.Easting << " "
              << (int)s.Northing << std::endl;

    std::cout << "6 Figure Grid Reference:\t" << OSGB36::grid_ref(s) << std::endl;

    std::cout << "Plus Code:\t" << WGS84::pluscode(ll) << std::endl;

    return 0;
}
