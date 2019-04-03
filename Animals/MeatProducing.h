#ifndef MEATPROD_H
#define MEATPROD_H

#include "FarmAnimal.h"

class MeatProducing : virtual public FarmAnimal{
    public:
        MeatProducing(int, int, bool);
};

#endif