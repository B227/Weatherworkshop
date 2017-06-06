#include <iostream>
#include "consol.h"

using namespace std;

consol::consol()
{
it = 0;
il = 0;
light[9]=200;
temp[9]=200;
}

void consol::inputLumen(int data)
{
    int x=0;
    if(light[9]==200){
        light[il]=data;
        il++;
    }else{
        for(int i=0;i<10;i++){
           x+=light[i];
        }
        x/=10;
        cout << "***************" << endl;
        cout << "* Light:      *" << endl;
        cout << "*    " << x << "      *" << endl;
        cout << "***************" << endl;
        light[9]=200;
        il = 0;
    }
}

void consol::inputTemp(int data)
{
    int x=0;
    if(temp[9]==200){
        temp[it]=data;
        it++;
    }else{
        for(int i=0;i<10;i++){
           x+=temp[i];
        }
        x/=10;
        cout << "***************" << endl;
        cout << "* Tempuratur: *" << endl;
        if(x>9){
            cout << "*    " << x << "       *" << endl;
        }else{
            cout << "*    " << x << "        *" << endl;
        }
        cout << "***************" << endl;
        temp[9]=200;
        it = 0;
   }
}
