#ifndef OSGB36_OBJECTS_HPP
#define OSGB36_OBJECTS_HPP
#ifndef ARDUINO
#include <cmath>
#include <string>

typedef std::string string_t;
#else
typedef String string_t;
#endif

namespace WGS84 {
struct LatLon {
    double Lat;
    double Lon;
    double Alt;
    bool error = false;
};
}

namespace OSGB36 {

struct LatLon {
    double Lat;
    double Lon;
    double Alt;
    bool error = false;
};

struct NorthingEasting {
    double Northing;
    double Easting;
    bool error = false;
};

}

#endif