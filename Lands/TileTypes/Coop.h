#ifndef COOP_H
#define COOP_H
#include "../Land.h"
/*Kelas Coop adalah turunan dari kelas Land dan merepresentasikan lahan pijakan yang di dalam kandang EggProducing Animals.*/

class Coop : public Land{
    public:
        //Constructor:
        Coop();
        //Method to grow grass chaange symbol into '#'':
        void growGrass();
        //Method to grow grass chaange symbol into 'o':
        void ungrowGrass();
};  
#endif
