#include <iostream>
#include <vector>
#include <fstream>
#include "fil.h"

using namespace std;

Fil::Fil():
    myport("COM9"), //\\\\.\\COM10 og COM9
    myTemp(1),
    myLight(2)
{
    file.open("vd.dat");
}

void Fil::writeFil(int sensorid, int push){
    static int i = 0;

    if (!file.is_open()) {
        cout << "Error - DB NOT LOADED";
    }
    data.push_back(push);
    if (sensorid == 1) {
        file << "Sensor ID : 1" << endl;
        file << "Measured Data : " << data[i] << endl;
        file << "--------------" << endl;
        i++;
    }
    else if (sensorid == 2) {
        file << "Sensor ID: 2" << endl;
        file << "Measured Data : " << data[i] << endl;
        file << "--------------" << endl;
        i++;
    }

}

void Fil::run(){
    char buffer[100];

        int bytesread=0;
        int total=0;
        memset(buffer,0,100);
        do {
            bytesread = myport.ReadData(buffer+total,100);
            total+=bytesread;
        } while (buffer[total-1]!='\n');
        if (myTemp.check(buffer,total)!=0){
            int y = myTemp.Celcius(buffer,total);
            co.inputTemp(y);
            writeFil(1,y);
        }
        if (myLight.check(buffer,total)!=0){
            int x = myLight.Lumen(buffer,total);
            co.inputLumen(x);
            writeFil(2,x);
        }


}


ostream& Fil::readFil(ostream &os) {
    std::vector<int>::iterator Iter;
    int i = 0;
    for (Iter = data.end(); Iter != data.begin(); Iter--){
        if (i >= 10){
            break;
        }
        else{
            os << *Iter << endl;
        }
    }
    return os;
}

