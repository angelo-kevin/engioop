#include "Land.h"

class Barn : public Land{
    private:
        char Symbol;
    public:
        Barn();
        char showSymbol();
};
