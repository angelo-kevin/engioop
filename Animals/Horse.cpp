#include "Horse.h"

Horse::Horse(int x, int y, bool l): FarmAnimal(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 'h';
    else simbol = 'H';
    threshold = 12;
}

void Horse::move(){

} //implementasi fungsi pure virtual dari parent

string Horse::sound(){
    return "neigh";
}

FarmProduct Horse::produceegg(){}

FarmProduct Horse::producemeat(){
    return HorseMeat();
}

FarmProduct Horse::producemilk(){}