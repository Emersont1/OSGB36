#ifndef OBJECTS_HPP
#define OBJECTS_HPP
#include <cmath>
#include <ellipsoids.hpp>
#include <utils.hpp>

namespace gps {
template <typename T>
class lon_lat;

template <typename T>
class ecef {
public:
    double x, y, z;

    ecef(double x, double y, double z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    // Other Methods (not implemented)
    //lon_lat<T> os_method();
    //lon_lat<T> zhus_algorithm();
    lon_lat<T> olsons_algorithm();
    lon_lat<T> to_lon_lat() { return olsons_algorithm(); }

    template <typename U>
    ecef<U> helmert();
};

template <typename T>
class lon_lat {
public:
    double longitude, latitude, altitude;

    lon_lat(double longitude, double latitude, double altitude)
        : longitude(longitude)
        , latitude(latitude)
        , altitude(altitude)
    {
    }

    gps::ecef<T> to_ecef();
};

}

#include <functions/helmert.hpp>
#include <functions/lon_lat.hpp>
#include <functions/olson.hpp>
#endif
