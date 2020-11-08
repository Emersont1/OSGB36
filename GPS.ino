#include <calculator.hpp>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>

TinyGPSPlus gps;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(17, 3);
  lcd.print("GPS");
}

void loop()
{
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // Parse 1s of NMEA sentences
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (Serial2.available())
    {
      char c = Serial2.read();
      //Serial.write(c); // stream back to PC for debug
      if (gps.encode(c))
        newData = true;
    }
  }

  if (newData)
  {
    lcd.setCursor(0, 3);

    lcd.print("SAT: ");
    if (gps.satellites.value() < 10)lcd.print(' ');
    lcd.print(gps.satellites.value());

    if (gps.location.isValid()) {
      // Serial.println("got GPS");
      //lcd.clear();

      WGS84::LatLon ll;

      ll.Lat = gps.location.lat();
      ll.Lon = gps.location.lng();
      ll.Alt = gps.altitude.meters();

      WGS84::ECEF ecef = WGS84::to_ECEF(ll);
      OSGB36::ECEF ecef2 = helmert_transform(ecef);
      OSGB36::LatLon ll2 = olsons_algorithm(ecef2);
      auto s = OSGB36::transverse_mercator(ll2);

      lcd.setCursor(0, 0);
      lcd.print(OSGB36::grid_ref(s));
      lcd.setCursor(14, 0);

      float speed = gps.speed.mph();
      if (speed < 100)
        lcd.print(' ');
      if (speed < 10)
        lcd.print(' ');
      lcd.print(speed, 0);
      lcd.setCursor(17, 0);
      lcd.print("mph");
      lcd.setCursor(0, 1);
      if (fabs( ll.Lat) < 10)lcd.print(' ');
      lcd.print(fabs( ll.Lat), 5);
      if ( ll.Lat > 0)lcd.print("\xDFN");
      if ( ll.Lat < 0)lcd.print("\xDFS");

      lcd.setCursor(0, 2);
      if (fabs( ll.Lon) < 10)lcd.print(' ');
      lcd.print(fabs(ll.Lon), 5);
      if (ll.Lon > 0)lcd.print("\xDFE");
      if (ll.Lon < 0)lcd.print("\xDFW");
      lcd.setCursor(9, 3);
      lcd.print(WGS84::pluscode(ll));

    }
  }
}
