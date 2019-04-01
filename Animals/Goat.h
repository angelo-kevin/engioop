#ifndef GOAT_H
#define GOAT_H

#include "MilkProducing.h"
#include "MeatProducing.h"

class Goat : public MilkProducing, public MeatProducing{
    public:
        Goat(bool l, int x, int y);
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'mbek'
};

#endif