#ifndef GOAT_H
#define GOAT_H

#include "MilkProducing.h"
#include "MeatProducing.h"
#include "../Product/FarmProduct/GoatMeat.h"
#include "../Product/FarmProduct/GoatMilk.h"

class Goat : public MilkProducing, public MeatProducing{
    public:
        Goat(int x, int y, bool l);
        void move(); //implementasi fungsi pure virtual dari parent
        void eat(); //makan
        string sound(); //suara 'mbek'
        FarmProduct produceMeat();
        FarmProduct produceMilk();
};

#endif