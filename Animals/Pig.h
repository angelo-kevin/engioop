#ifndef PIG_H
#define PIG_H

#include "MeatProducing.h"

class Pig : public MeatProducing{
    public:
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        void sound(); //suara 'squeak'
};

#endif