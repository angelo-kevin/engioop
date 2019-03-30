#ifndef CHICKEN_H
#define CHICKEN_H

#include "EggProducing.h"
#include "MeatProducing.h"

class Chicken : public EggProducing, public MeatProducing{
    public:
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        void sound(); //suara 'petok'
};

#endif