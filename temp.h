#ifndef TEMP_H
#define TEMP_H
#include "sensor.h"

class Temp: public Sensor
{
public:
    int check(char buf[],int tot);
    float Celcius(char buf[],int tot);
    Temp(int id);
private:
    float data;
};

#endif // TEMP_H
