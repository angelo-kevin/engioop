#ifndef HORSE_H
#define HORSE_H

#include "MeatProducing.h"
#include "../Product/FarmProduct/HorseMeat.h"

class Horse : public MeatProducing{
    public:
        Horse(int x, int y, bool l);
        void move(); //implementasi fungsi pure virtual dari parent
        void eat(); //makan
        string sound(); //suara 'neigh'
        FarmProduct produceMeat();
};

#endif