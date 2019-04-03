#include "MeatProducing.h"

MeatProducing::MeatProducing(int x, int y, bool l): FarmAnimal(x,y,l){}

string MeatProducing::producemeat(){
    return "daging";
}

string MeatProducing::produce(){
    return "i produce meat";
}