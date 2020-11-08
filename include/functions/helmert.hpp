template <>
template <>
gps::ecef<gps::airy1830> gps::ecef<gps::wgs84>::helmert<gps::airy1830>()
{
    const double t_x = -446.448;
    const double t_y = 125.157;
    const double t_z = -542.060;
    const double s = 1 + 20.4894 / 1000000;
    const double r_x = seconds_to_radians(-0.1502);
    const double r_y = seconds_to_radians(-0.2470);
    const double r_z = seconds_to_radians(-0.8421);
    double X = t_x + s * x - r_z * y + r_y * z;
    double Y = t_y + r_z * x + s * y - r_x * z;
    double Z = t_z - r_y * x + r_x * y + s * z;
    return gps::ecef<gps::airy1830>(X, Y, Z);
}