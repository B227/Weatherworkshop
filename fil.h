#ifndef FIL_H
#define FIL_H

#include <iostream>
#include <vector>
#include <fstream>
#include "consol.h"
#include "light.h"
#include "temp.h"
#include "serial.h"

using namespace std;

class Fil {
private:
    std::vector<int> data;
    std::ofstream file;
    void openFile(std::string filename);
    Temp myTemp;
    Light myLight;
public:
    consol co;
    Serial myport;
    Fil();
    void writeFil(int sensorid, int push);
    ostream& readFil(ostream &os);
    void run();
};

#endif // FIL_H
