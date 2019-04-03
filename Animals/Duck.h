#ifndef DUCK_H
#define DUCK_H

#include "EggProducing.h"
#include "MeatProducing.h"
#include "../Product/FarmProduct/DuckEgg.h"
#include "../Product/FarmProduct/DuckMeat.h"

class Duck : public EggProducing, public MeatProducing{
    public:
        Duck(int x, int y, bool l);
        void move(); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'kwek'
        FarmProduct produceEgg();
        FarmProduct produceMeat();
};

#endif