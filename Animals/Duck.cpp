#include "Duck.h"

Duck::Duck(bool l, int x, int y): FarmAnimal(x,y,l){
    if (lapar) simbol = 'd';
    else simbol = 'D';
    threshold = 8;
}

void Duck::move(vector<vector<Cells*> >){

} //implementasi fungsi pure virtual dari parent

string Duck::sound(){
    return "kwek";
}