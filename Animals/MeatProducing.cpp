#include "MeatProducing.h"

string MeatProducing::produce(){
    return "daging";
}

MeatProducing::MeatProducing(int x, int y, bool l) : FarmAnimal(x,y,l){

}