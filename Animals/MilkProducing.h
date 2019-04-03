#ifndef MILKPROD_H
#define MILKPROD_H

#include "FarmAnimal.h"

class MilkProducing : virtual public FarmAnimal{
    public:
        MilkProducing(int, int, bool);
        string producemilk(); //menghasilkan susu
};

#endif