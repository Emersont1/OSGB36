#include <iostream>

#include <objects.hpp>

int main(int argc, char const* argv[])
{
    gps::lon_lat<gps::wgs84> l(53.2343130000, -0.5360620000, 80.0000000000);
    for (int i = 0; i < 10; i++) {
        std::cout << "{ " << l.longitude << ", " << l.latitude << ", " << l.altitude << " }" << std::endl;
        l = l.to_ecef().to_lon_lat();
    }
}
