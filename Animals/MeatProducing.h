#ifndef MEATPROD_H
#define MEATPROD_H

#include "FarmAnimal.h"

class MeatProducing : public FarmAnimal{
    public:
        string produce(); //menghasilkan daging
        MeatProducing(int, int, bool);
};

#endif