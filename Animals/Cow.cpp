#include "Cow.h"

Cow::Cow(int x, int y, bool l): FarmAnimal(x,y,l), MilkProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 's';
    else simbol = 'S';
    threshold = 10;
}

void Cow::move(){

} //implementasi fungsi pure virtual dari parent

string Cow::sound(){
    return "moo";
}

FarmProduct Cow::produceMeat(){
    return CowMeat();
}

FarmProduct Cow::produceMilk(){
    return CowMilk();
}