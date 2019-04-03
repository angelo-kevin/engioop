#ifndef COW_H
#define COW_H

#include "MilkProducing.h"
#include "MeatProducing.h"

class Cow : public MilkProducing, public MeatProducing{
    public:
        Cow(bool l, int x, int y);
        void move(); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'moo'
};

#endif