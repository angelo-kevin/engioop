#ifndef HORSE_H
#define HORSE_H

#include "MeatProducing.h"

class Horse : public MeatProducing{
    public:
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        void sound(); //suara 'neigh'
};

#endif