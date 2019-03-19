#include "Land.h"

class Grassland : public Land{
    private:
        char Symbol;
    public:
        char showSymbol();
        void growGrass();
};
