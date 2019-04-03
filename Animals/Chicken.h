#ifndef CHICKEN_H
#define CHICKEN_H

#include "EggProducing.h"
#include "MeatProducing.h"

class Chicken : public EggProducing, public MeatProducing{
    public:
        Chicken(bool l, int x, int y);
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'petok'
};

#endif