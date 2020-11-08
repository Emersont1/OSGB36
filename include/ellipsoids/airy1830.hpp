#ifndef AIRY1830_HPP
#define AIRY1830_HPP

namespace gps {
struct airy1830 {
    static constexpr double a = 6377563.396; // 6378137.0;
    static constexpr double b = 6356256.909; // 6356752.3141;
    static constexpr double e_sq = (a * a - b * b) / (a * a);

private:
    airy1830() { }
};
}

#endif