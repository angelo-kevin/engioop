#ifndef PIG_H
#define PIG_H

#include "MeatProducing.h"

class Pig : public MeatProducing{
    public:
        Pig(int x, int y, bool l);
        void move(); //implementasi fungsi pure virtual dari parent
        string sound(); //suara 'squeak'
};

#endif