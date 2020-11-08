#ifndef WGS84_HPP
#define WGS84_HPP

namespace gps {
struct wgs84 {
    static constexpr double a = 6378137.0;
    static constexpr double b = 6356752.314245;
    static constexpr double e_sq = (a * a - b * b) / (a * a);

private:
    wgs84() { }
};

}

#endif