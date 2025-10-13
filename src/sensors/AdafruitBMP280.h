#ifndef BMP280_SENSOR_H
#define BMP280_SENSOR_H

#include "sensor.h"
#include <Adafruit_BMP280.h>

class Bmp280Sensor : public Sensor {
public:
    Bmp280Sensor();
    bool setup() override;
    float read() override;

private:
    Adafruit_BMP280 bmp;
};

#endif // BMP280_SENSOR_H