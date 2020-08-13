#include <calculator.hpp>
#include <constants.hpp>

OSGB36::NorthingEasting OSGB36::transverse_mercator(OSGB36::LatLon Coord)
{
    OSGB36::NorthingEasting ne;
    // Check the data is in good range
    
    if (((Coord.Lon < -7) || (Coord.Lon > 8)) && ((Coord.Lat < 49) || (Coord.Lat > 60))) {
        ne.error = true;
        // calculate it anyway, as you can get about as far east as verona
        //and still have a 6 Figure grid reference
    }

    double lat = OSGB36::degrees_to_radians(Coord.Lat);
    double lon = OSGB36::degrees_to_radians(Coord.Lon);
    double ht = Coord.Alt;

    double a = OSGB36::a;
    a *= OSGB36::f0;
    double b = OSGB36::b;
    b *= OSGB36::f0;

    double n = (a - b) / (a + b);
    double e2 = ((a * a) - (b * b)) / (a * a);
    double nu = (a / pow(1 - e2 * pow(sin(lat), 2.0), 0.5));
    double rho = ((a * (1 - e2)) / pow(1 - e2 * pow(sin(lat), 2.0), 1.5));
    double n2 = (nu / rho) - 1;

    double dLat = lat - OSGB36::lat0; // difference in latitude
    double sLat = lat + OSGB36::lat0; // sum of latitude

    double M = OSGB36::compute_meridan_arc(dLat, sLat, n, b);

    double P = lon - OSGB36::lon0; // difference in longitude

    // The following are taken from [1] pp10-11
    double I = M + OSGB36::n0;
    double II = (nu / 2) * sin(lat) * cos(lat);
    double III = (nu / 24) * sin(lat) * pow(cos(lat), 3.0) * (5 - pow(tan(lat), 2.0) + (9 * n2));
    double IIIA = (nu / 720) * sin(lat) * pow(cos(lat), 5.0) * (61 - (58 * pow(tan(lat), 2.0)) + pow(tan(lat), 4.0));
    double IV = nu * cos(lat);
    double V = (nu / 6) * pow(cos(lat), 3.0) * ((nu / rho) - pow(tan(lat), 2.0));
    double VI = (nu / 120) * pow(cos(lat), 5.0) * (5 - (18 * pow(tan(lat), 2.0)) + pow(tan(lat), 4.0) + (14 * n2) - (58 * pow(tan(lat), 2.0) * n2));

    double y = I + (pow(P, 2.0) * II) + (pow(P, 4.0) * III) + (pow(P, 6.0) * IIIA);
    double x = OSGB36::e0 + (P * IV) + (pow(P, 3.0) * V) + (pow(P, 5.0) * VI);

    /*
        Shift s = (Shift)mShifts.CalculateShift(x, y);
        double lLat = x + s.Easting;
        double lLon = y + s.Northing;
        double lHeight = pHeight - s.Height;
    */

    ne.Easting = x;
    ne.Northing = y;

    return ne;
}