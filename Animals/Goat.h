#ifndef GOAT_H
#define GOAT_H

#include "MilkProducing.h"
#include "MeatProducing.h"

class Goat : public MilkProducing, public MeatProducing{
    public:
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        void sound(); //suara 'mbek'
};

#endif