#ifndef OSGB36_CONSTS_HPP
#define OSGB36_CONSTS_HPP
#include <calculator.hpp>

namespace OSGB36 {
extern const double a = 6377563.396; //6378137.0;
extern const double b = 6356256.909; //6356752.3141;
extern const double e_sq = (a * a - b * b) / (a * a);
extern const double epsilon_sq = (a * a - b * b) / (b * b);

extern const double lat0 = 0.85521133347722149269260847655942;
extern const double lon0 = -0.03490658503988659153847381536977;

extern const double e0 = 400000.0;
extern const double n0 = -100000.0;
extern const double f0 = 0.9996012717;

extern const double t_x = -446.448;
extern const double t_y = 125.157;
extern const double t_z = -542.060;
extern const double s = 1 + 20.4894 / 1000000;
extern const double r_x = OSGB36::seconds_to_radians(-0.1502);
extern const double r_y = OSGB36::seconds_to_radians(-0.2470);
extern const double r_z = OSGB36::seconds_to_radians(-0.8421);

}

namespace WGS84 {
extern const double a = 6378137.0;
extern const double b = 6356752.314245;
extern const double e_sq = (a * a - b * b) / (a * a);
};

#endif