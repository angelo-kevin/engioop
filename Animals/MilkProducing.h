#ifndef MILKPROD_H
#define MILKPROD_H

#include "FarmAnimal.h"

class MilkProducing : public FarmAnimal{
    public:
        string produce(); //menghasilkan susu
};

#endif