#include <calculator.hpp>
#include <constants.hpp>

OSGB36::LatLon zhus_algorithm(double& x, double& y, double& z)
{
    // https://hal.archives-ouvertes.fr/hal-01704943v2/document
    using namespace OSGB36;
    double w = sqrt(x * x + y * y); //1

    if (w == 0) {
        LatLon ll;
        ll.Lat = radians_to_degrees(sign(z) * (M_PI / 2));
        ll.Lon = 0;
        ll.Alt = sign(z) * (z - b);
        return ll;
    }

    double l = e_sq / 2; // 2
    double m = pow(w / a, 2); // 3
    double n = pow((1 - e_sq) * z, 2); // 4
    double i = -(2 * pow(l, 2) + m + n) / 2;
    double k = pow(l, 2) * (pow(l, 2) - m - n);
    double q = pow(m + n - 4 * pow(l, 2), 3) / 216 + m * n * pow(l, 2);
    double D = sqrt((2 * q - m * n * pow(l, 2)) * m * n * pow(l, 2));
    double beta = i / 3 - pow(q + D, 1.0 / 3) - pow(q - D, 1.0 / 3);
    double t = sqrt(sqrt(pow(beta, 2) - k) - (beta + i) / 2) - sign(m - n) * sqrt((beta - i) / 2);
    double w_1 = w / (t + l);
    double z_1 = (1 - e_sq) * z / (t - l);

    double phi = atan2(z_1, (1 - e_sq) * w_1);
    double lambda = 2 * atan2(w - x, y);
    if (lambda > M_PI)
        lambda -= 2 * M_PI;

    LatLon ll;
    ll.Alt = sign(t - 1 + l) * sqrt(pow(w - w_1, 2) + pow(z - z_1, 2));

    ll.Lat = radians_to_degrees(phi);
    ll.Lon = radians_to_degrees(lambda);
    return ll;
}