#include <calculator.hpp>
#include <constants.hpp>

OSGB36::ECEF helmert_transform(WGS84::ECEF in)
{
    double& X = in.x;
    double& Y = in.y;
    double& Z = in.z;
    OSGB36::ECEF out;
    out.x = OSGB36::t_x + OSGB36::s * X - OSGB36::r_z * Y + OSGB36::r_y * Z;
    out.y = OSGB36::t_y + OSGB36::r_z * X + OSGB36::s * Y - OSGB36::r_x * Z;
    out.z = OSGB36::t_z - OSGB36::r_y * X + OSGB36::r_x * Y + OSGB36::s * Z;
    return out;
}
