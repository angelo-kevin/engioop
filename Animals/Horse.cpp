#include "Horse.h"

Horse::Horse(bool l, int x, int y): FarmAnimal(x,y,l){
    if (lapar) simbol = 'h';
    else simbol = 'H';
    threshold = 12;
}

void Horse::move(vector<vector<Cells*> >){

} //implementasi fungsi pure virtual dari parent

string Horse::sound(){
    return "neigh";
}