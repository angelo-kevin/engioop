#ifndef CHICKEN_H
#define CHICKEN_H

#include "EggProducing.h"
#include "MeatProducing.h"
//#include "EggProducing.cpp"
class Chicken : public EggProducing, public MeatProducing{
    public:
        Chicken(int x, int y, bool l);
        void move(); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'petok'
};

#endif