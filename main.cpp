#include <iostream>

#include <calculator.hpp>

OSGB36::LatLon ordonnance_survey_algorithm(double& x, double& y, double& z);

int main(int argc, char const* argv[])
{

    WGS84::LatLon ll; // populate from GPS reciever

    // Lincoln Cathedral
    ll.Lat = 53.234313;
    ll.Lon = -0.536062;
    ll.Alt = 80;

    OSGB36::LatLon ll2 = geoid_convert(ll);
    std::cout.precision(10);
    std::cout << "WGS84 Lon/Lat/Alt:\t\t" << std::fixed << ll.Lat << " " << std::fixed << ll.Lon<<" "<<  std::fixed << ll.Alt << std::endl;
    std::cout << "OSGB36 Lon/Lat/Alt:\t\t" << std::fixed << ll2.Lat << " " << std::fixed << ll2.Lon << " "<<  std::fixed << ll2.Alt << std::endl;

    auto s = OSGB36::transverse_mercator(ll2);

    std::cout<< "OSGB36 Northing & Easting:\t" << (int)s.Easting << " "<< (int)s.Northing << std::endl;
    
    std::cout<< "6 Figure Grid Reference:\t"<< OSGB36::grid_ref(s)<<std::endl;

    return 0;
}
