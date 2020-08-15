#include <calculator.hpp>
#include <constants.hpp>

OSGB36::LatLon ordinance_survey_algorithm(double& x, double& y, double& z)
{
    using namespace OSGB36;
    double lambda = atan2(y, x);
    double old_phi;
    double p = sqrt(x * x + y * y);
    double phi = atan2(x, p * (1 - e_sq));

    do {
        old_phi = phi;
        double v = a / sqrt(1 - e_sq * pow(sin(phi), 2));
        phi = atan2(z + e_sq * v * sin(phi), p);

    } while (log10(abs(phi - old_phi)) > -14);

    double v = a / sqrt(1 - e_sq * pow(sin(phi), 2));
    LatLon ll;
    ll.Lon = radians_to_degrees(lambda);
    ll.Lat = radians_to_degrees(phi);
    ll.Alt = p / cos(phi) - v;

    return ll;
}