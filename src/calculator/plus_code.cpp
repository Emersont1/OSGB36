#include <calculator.hpp>

string_t WGS84::pluscode(WGS84::LatLon in)
{
    string_t index = "23456789CFGHJMPQRVWX";
    int lat = (int)((in.Lat + 90) * 8000);
    int lon = (int)((in.Lon + 180) * 8000);
    string_t code = "";
    for (int i = 0; i < 5; i++) {
        code = index[lon % 20] + code;
        code = index[lat % 20] + code;
        if (i == 0) {
            code = "+" + code;
        }
        lon /= 20;
        lat /= 20;
    }
    return code;
    //
}