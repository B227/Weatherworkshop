#ifndef LIGHT_H
#define LIGHT_H
#include "sensor.h"

class Light: public Sensor
{
public:
    int check(char buf[], int tot);
    float Lumen(char bufferData[], int tot);
    Light(int id);
private:
    float data;
};

#endif // LIGHT_H
