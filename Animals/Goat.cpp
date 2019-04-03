#include "Goat.h"

Goat::Goat(bool l, int x, int y): FarmAnimal(x,y,l){
    if (lapar) simbol = 'g';
    else simbol = 'G';
    threshold = 10;
}

void Goat::move(vector<vector<Cells*> >){

} //implementasi fungsi pure virtual dari parent

string Goat::sound(){
    return "mbek";
}