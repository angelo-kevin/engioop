#include "Cow.h"

Cow::Cow(bool l, int x, int y): FarmAnimal(x,y,l), MilkProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 's';
    else simbol = 'S';
    threshold = 10;
}

void Cow::move(){

} //implementasi fungsi pure virtual dari parent

string Cow::sound(){
    return "moo";
}