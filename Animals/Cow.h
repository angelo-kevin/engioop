#ifndef COW_H
#define COW_H

#include "MilkProducing.h"
#include "MeatProducing.h"
#include "../Product/FarmProduct/CowMeat.h"
#include "../Product/FarmProduct/CowMilk.h"

class Cow : public MilkProducing, public MeatProducing{
    public:
        Cow(int x, int y, bool l);
        void move(); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'moo'
        FarmProduct produceMeat();
        FarmProduct produceMilk();
};

#endif