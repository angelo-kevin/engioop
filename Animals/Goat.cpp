#include "Goat.h"

Goat::Goat(int x, int y, bool l): FarmAnimal(x,y,l), MilkProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 'g';
    else simbol = 'G';
    threshold = 10;
}

void Goat::move(){

} //implementasi fungsi pure virtual dari parent

string Goat::sound(){
    return "mbek";
}