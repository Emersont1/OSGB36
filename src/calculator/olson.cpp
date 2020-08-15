#include <calculator.hpp>
#include <constants.hpp>

// http://danceswithcode.net/engineeringnotes/geodetic_to_ecef/geodetic_to_ecef.html
void _olsons_algorithm(double& x, double& y, double& z, double a, double e_sq, double* lon, double* lat, double* alt);

OSGB36::LatLon OSGB36::olsons_algorithm(OSGB36::ECEF p)
{
    OSGB36::LatLon ll;
    _olsons_algorithm(p.x, p.y, p.z, OSGB36::a, OSGB36::e_sq, &ll.Lon, &ll.Lat, &ll.Alt);
    return ll;
}

WGS84::LatLon WGS84::olsons_algorithm(WGS84::ECEF p)
{
    WGS84::LatLon ll;
    _olsons_algorithm(p.x, p.y, p.z, WGS84::a, WGS84::e_sq, &ll.Lon, &ll.Lat, &ll.Alt);
    return ll;
}

void _olsons_algorithm(double& x, double& y, double& z, double a, double e_sq, double* lon, double* lat, double* alt)
{
    double a1 = a * e_sq;
    const double a2 = a1 * a1;
    const double a3 = a1 * e_sq / 2;
    const double a4 = 2.5 * a2;
    const double a5 = a1 + a3;
    const double a6 = 1 - e_sq;

    double zp, w2, w, r2, r, s2, c2, s, c, ss;
    double g, rg, rf, u, v, m, f, p;
    double n; //, lat, lon, alt;

    zp = abs(z);
    w2 = x * x + y * y;
    w = sqrt(w2);
    r2 = w2 + z * z;
    r = sqrt(r2);
    *lon = atan2(y, x); // Lon (final)
    s2 = z * z / r2;
    c2 = w2 / r2;
    u = a2 / r;
    v = a3 - a4 / r;
    if (c2 > 0.3) {
        s = (zp / r) * (1.0 + c2 * (a1 + u + s2 * v) / r);
        *lat = asin(s); // Lat
        ss = s * s;
        c = sqrt(1.0 - ss);
    } else {
        c = (w / r) * (1.0 - s2 * (a5 - u - c2 * v) / r);
        *lat = acos(c); // Lat
        ss = 1.0 - c * c;
        s = sqrt(ss);
    }
    g = 1.0 - e_sq * ss;
    rg = a / sqrt(g);
    rf = a6 * rg;
    u = w - rg * c;
    v = zp - rf * s;
    f = c * u + s * v;
    m = c * v - s * u;
    p = m / (rf / g + f);
    *lat += p; // Lat
    *alt = f + m * p / 2.0; // Altitude
    if (z < 0.0) {
        *lat *= -1.0; // Lat
    }
    *lat = radians_to_degrees(*lat);
    *lon = radians_to_degrees(*lon);
}