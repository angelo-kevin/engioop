#include "Duck.h"

Duck::Duck(int x, int y, bool l): FarmAnimal(x,y,l), EggProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 'd';
    else simbol = 'D';
    threshold = 8;
}

void Duck::move(){

} //implementasi fungsi pure virtual dari parent

string Duck::sound(){
    return "kwek";
}