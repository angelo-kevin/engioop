#ifndef COMMON_H
#define COMMON_H
#include "Cell.h"
#include <vector>
using namespace std;

//Global matrix variable for map accross files:
extern vector<vector<Cell*> > gamemap;
//After this you need to define it again at .cpp file ONCE

//Vector of farmanimal ptr:
extern vector<FarmAnimal*> animalList;

//Vector of facilities ptr:
extern vector<Facility*> facilityList;
#endif
