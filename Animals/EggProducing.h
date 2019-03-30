#ifndef EGGPROD_H
#define EGGPROD_H

#include "FarmAnimal.h"

class EggProducing : public FarmAnimal{
    public:
        string produce(); //menghasilkan telur
};

#endif