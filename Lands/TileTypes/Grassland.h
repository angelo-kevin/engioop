#ifndef GRASSLAND_H
#define GRASSLAND_H
#include "../Land.h"

class Grassland : public Land{
    public:
        //Constructor:
        Grassland();
        //Method to grow grass chaange symbol into '#'':
        void growGrass();
        //Method to grow grass chaange symbol into '.':
        void ungrowGrass();
};

#endif
