#ifndef DUCK_H
#define DUCK_H

#include "EggProducing.h"
#include "MeatProducing.h"

class Duck : public EggProducing, public MeatProducing{
    public:
        Duck(bool l, int x, int y);
        void move(); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'kwek'
};

#endif