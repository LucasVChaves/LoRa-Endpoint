#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    virtual ~Sensor() = default;
    virtual bool setup() = 0;
    virtual float read() = 0; 
};

#endif