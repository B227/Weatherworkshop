#include "light.h"
#include <cmath>

Light::Light(int i)

{
id=i;
}

int Light::check(char buf[], int tot)
{
    SetBuffer(buf,tot);
    if (Read(id)==0)
        return 0;
    else
        return 1;
}

float Light::Lumen(char buf[],int tot)
{
    float floating=0;
    SetBuffer(buf,tot);
    Read(id);
    floating=rawData;
    //floating=floating/1024;
    //float potent = 1.6482*floating;
    data = 1023 - floating;
    //data=0.1624*exp(potent);
    return data;
}


