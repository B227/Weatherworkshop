#include "sensor.h"

Sensor::Sensor()
{
    sampleNumber=0;
}

int Sensor::Read(int sensorId)
{
    if(sensorId == 1){
        if(bufferID ==1){
            rawData = bufferData;
            return 1;
        }
    else{
            return 0;
        }
    }
    if(sensorId == 2){
        if(bufferID == 2){
            rawData = bufferData;
            return 1;
        }
    else{
            return 0;
        }
    }
}


void Sensor::SetBuffer(char buffer[], int total)
{
    int id = 0;
    int data = 0;
    int test = 1;
    bufferID = buffer[0]-48;
    //cout<< bufferID <<":";
    for(int i=total-3;i>0;i--){
        data=data+((buffer[i]-48)*test);
        test=test*10;
    }
    bufferData=data;
    //cout<<data<<"\n";
}

