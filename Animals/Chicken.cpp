#include "Chicken.h"

Chicken::Chicken(bool l, int x, int y): FarmAnimal(x,y,l), EggProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 'c';
    else simbol = 'C';
    threshold = 8;
}

void Chicken::move(){

} //implementasi fungsi pure virtual dari parent

string Chicken::sound(){
    return "petok";
} //suara 'petok'