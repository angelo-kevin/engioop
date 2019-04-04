#ifndef COMMON_H
#define COMMON_H
#include "Cell.h"
#include <vector>
using namespace std;

//Global matrix variable for map accross files:
extern vector<vector<Cell*> > gamemap;
//After this you need to define it again at .cpp file ONCE

extern vector<FarmAnimal*> animalList;
#endif
