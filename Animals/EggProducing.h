#ifndef EGGPROD_H
#define EGGPROD_H

#include "FarmAnimal.h"

class EggProducing : virtual public FarmAnimal{
    public:
        EggProducing(int, int, bool);
        string produceegg(); //menghasilkan telur
};

#endif