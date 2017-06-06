#include "temp.h"

Temp::Temp(int i)
{
id=i;
}

int Temp::check(char buf[], int tot)
{
    SetBuffer(buf,tot);
    if (Read(id)==0)
        return 0;
    else
        return 1;
}

float Temp::Celcius(char buf[], int tot)
{
    float floating=0;
    SetBuffer(buf,tot);
    Read(id);
    floating=rawData;
    data=(floating*(5000/1024)-500)/10;
    return data;
}



