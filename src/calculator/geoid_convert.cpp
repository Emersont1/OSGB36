#include <calculator.hpp>
#include <constants.hpp>

OSGB36::LatLon geoid_convert(WGS84::LatLon old)
{
    // convert to ECEF
    double phi = OSGB36::degrees_to_radians(old.Lat);
    double lambda = OSGB36::degrees_to_radians(old.Lon);
    double& h = old.Alt;
    double n = WGS84::a / sqrt(1 - WGS84::e_sq * pow(sin(phi), 2));

    double X = (n + h) * cos(phi) * cos(lambda);
    double Y = (n + h) * cos(phi) * sin(lambda);
    double Z = ((1 - WGS84::e_sq) * n + h) * sin(phi);

    // transform
    double x = OSGB36::t_x + OSGB36::s * X - OSGB36::r_z * Y + OSGB36::r_y * Z;
    double y = OSGB36::t_y + OSGB36::r_z * X + OSGB36::s * Y - OSGB36::r_x * Z;
    double z = OSGB36::t_z - OSGB36::r_y * X + OSGB36::r_x * Y + OSGB36::s * Z;

    return olsons_algorithm(x, y, z);
}
