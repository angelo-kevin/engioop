#include "Pig.h"
//#include "MeatProducing.cpp"

Pig::Pig(int x, int y, bool l): FarmAnimal(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 'p';
    else simbol = 'P';
    threshold = 12;
}

void Pig::move(){

} //implementasi fungsi pure virtual dari parent

string Pig::sound(){
    return "squeak";
}

FarmProduct Pig::produceegg(){}

FarmProduct Pig::producemeat(){
    return PigMeat();
}

FarmProduct Pig::producemilk(){}