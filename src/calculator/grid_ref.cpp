#include <calculator.hpp>
#include <constants.hpp>
#include <iostream>

const string_t alphabet = "ABCDEFGHJKLMNOPQRSTUVWXYZ";

inline string_t format(int num, int width)
{
    string_t base
#ifdef ARDUINO
        = String(num, DEC);
#else
        = std::to_string(num);
#endif

    while (base.length() < width) {
        base = "0" + base;
    }
    return base;
}

string_t OSGB36::grid_ref(OSGB36::NorthingEasting NE)
{

    unsigned int new_northing = (int)(500050 + NE.Northing);
    unsigned int new_easting = (int)(1000050 + NE.Easting);

    unsigned char nl1 = new_northing / 500000;
    unsigned int n = new_northing % 500000;
    unsigned char nl2 = n / 100000;
    unsigned int n2 = n % 100000;

    unsigned char el1 = new_easting / 500000;
    unsigned int e = new_easting % 500000;
    unsigned char el2 = e / 100000;
    unsigned int e2 = e % 100000;

    string_t ref;

    string_t s;
    s += alphabet[(int)el1 + 5 * (4 - nl1)];
    s += alphabet[(int)el2 + 5 * (4 - nl2)];
    s += " ";
    s += format(e2 / 100, 3);
    s += " ";
    s += format(n2 / 100, 3);
    return s;
}
