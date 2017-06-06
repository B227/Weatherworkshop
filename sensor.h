#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <iostream>

using namespace std;

class Sensor
{
protected:
    int Read(int sensorId);
    int sampleNumber;
    int id;
    int bufferData;
    int bufferID;
    int rawData;

public:
    Sensor();
    void SetBuffer(char buffer[],int total);
};

#endif // SENSOR_H
