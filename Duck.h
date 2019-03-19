#include "EggProducing.h"
#include "MeatProducing.h"

class Duck : public EggProducing, public MeatProducing{
    public:
        void move(vector<vector<Cells*> >); //implementasi fungsi pure virtual dari parent
        void sound(); //suara 'kwek'
};
