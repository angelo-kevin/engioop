#ifndef BARN_H
#define BARN_H
#include "../Land.h"
/* Kelas Barn adalah turunan dari kelas Land dan merepresentasikan lahan pijakan yang di dalam kandang dan MeatProducing Animals.*/
class Barn : public Land{
    public:
        //Konstruktor
        Barn();
        //Method to grow grass chaange symbol into '#':
        void growGrass();
        //Method to grow grass chaange symbol into 'x':
        void ungrowGrass();
};
#endif
