#ifndef PIG_H
#define PIG_H

#include "MeatProducing.h"

class Pig : public MeatProducing{
    public:
        Pig(bool l, int x, int y);
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'squeak'
};

#endif