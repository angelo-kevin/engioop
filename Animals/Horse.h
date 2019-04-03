#ifndef HORSE_H
#define HORSE_H

#include "MeatProducing.h"

class Horse : public MeatProducing{
    public:
        Horse(bool l, int x, int y);
        void move(); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'neigh'
};

#endif