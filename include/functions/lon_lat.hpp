template <typename T>
inline gps::ecef<T> gps::lon_lat<T>::to_ecef()
{
    double phi = degrees_to_radians(latitude);
    double lambda = degrees_to_radians(longitude);
    double& h = altitude;
    double n = T::a / sqrt(1 - T::e_sq * pow(sin(phi), 2));

    double x = (n + h) * cos(phi) * cos(lambda);
    double y = (n + h) * cos(phi) * sin(lambda);
    double z = ((1 - T::e_sq) * n + h) * sin(phi);
    return ecef<T>(x, y, z);
}