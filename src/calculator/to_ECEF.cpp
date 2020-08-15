#include <calculator.hpp>
#include <constants.hpp>

WGS84::ECEF WGS84::to_ECEF(WGS84::LatLon in)
{
    double phi = degrees_to_radians(in.Lat);
    double lambda = degrees_to_radians(in.Lon);
    double& h = in.Alt;
    double n = WGS84::a / sqrt(1 - WGS84::e_sq * pow(sin(phi), 2));
    WGS84::ECEF out;
    out.x = (n + h) * cos(phi) * cos(lambda);
    out.y = (n + h) * cos(phi) * sin(lambda);
    out.z = ((1 - WGS84::e_sq) * n + h) * sin(phi);
    return out;
}