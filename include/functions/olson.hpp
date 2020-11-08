template <typename T>
inline gps::lon_lat<T> gps::ecef<T>::olsons_algorithm()
{
    double a1 = T::a * T::e_sq;
    const double a2 = a1 * a1;
    const double a3 = a1 * T::e_sq / 2;
    const double a4 = 2.5 * a2;
    const double a5 = a1 + a3;
    const double a6 = 1 - T::e_sq;

    double zp, w2, w, r2, r, s2, c2, s, c, ss;
    double g, rg, rf, u, v, m, f, p;
    double n, lat, lon, alt;

    zp = abs(z);
    w2 = x * x + y * y;
    w = sqrt(w2);
    r2 = w2 + z * z;
    r = sqrt(r2);
    lon = atan2(y, x); // Lon (final)
    s2 = z * z / r2;
    c2 = w2 / r2;
    u = a2 / r;
    v = a3 - a4 / r;
    if (c2 > 0.3) {
        s = (zp / r) * (1.0 + c2 * (a1 + u + s2 * v) / r);
        lat = asin(s); // Lat
        ss = s * s;
        c = sqrt(1.0 - ss);
    } else {
        c = (w / r) * (1.0 - s2 * (a5 - u - c2 * v) / r);
        lat = acos(c); // Lat
        ss = 1.0 - c * c;
        s = sqrt(ss);
    }
    g = 1.0 - T::e_sq * ss;
    rg = T::a / sqrt(g);
    rf = a6 * rg;
    u = w - rg * c;
    v = zp - rf * s;
    f = c * u + s * v;
    m = c * v - s * u;
    p = m / (rf / g + f);
    lat += p; // Lat
    alt = f + m * p / 2.0; // Altitude
    if (z < 0.0) {
        lat *= -1.0; // Lat
    }
    return gps::lon_lat<T>(radians_to_degrees(lon), radians_to_degrees(lat), alt);
}