#include "MilkProducing.h"
#include "MeatProducing.h"

class Cow : public MilkProducing, public MeatProducing{
    public:
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        void sound(); //suara 'moo'
};
