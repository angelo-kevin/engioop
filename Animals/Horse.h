#ifndef HORSE_H
#define HORSE_H

#include "MeatProducing.h"

class Horse : public MeatProducing{
    public:
        Horse(int x, int y, bool l);
        void move(); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'neigh'
};

#endif