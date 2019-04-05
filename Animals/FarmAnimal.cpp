//includes cell in cpp to prevent undefined reference becoz of forward declaration in cell.h
#include "FarmAnimal.h"
#include "../Cell.h"
#include <iostream>
using namespace std;

FarmAnimal::FarmAnimal(int _x, int _y, bool _l){
    x = _x;
    y = _y;
    lapar = _l;
    simbol = '\0';
    threshold = -999;
} //ctor

char FarmAnimal::showSimbol(){
    return simbol;
} //mengembalikan nilai simbol

void FarmAnimal::revSimbol(){
    if (simbol>='a' && simbol<='z') simbol = simbol-'a'+'A';
    else simbol = simbol-'A'+'a';
} //mengubah nilai simbol dari objek yang akan ditunjukkan di map

int FarmAnimal::getThreshold(){
    return threshold;
} //mengembalikan nilai threshold dari objek

void FarmAnimal::minThreshold(){
    threshold--;
}

bool FarmAnimal::getLapar(){
    return lapar;
} //mengecek apakah objek dari kelas ini lapar atau tidak

void FarmAnimal::revLapar(){
    lapar = !lapar;
    revSimbol();
} //mengubah nilai lapar dari objek

int FarmAnimal::getX(){
    return x;
}

int FarmAnimal::getY(){
    return y;
}

void FarmAnimal::setX(int _x){
    x = _x;
}

void FarmAnimal::setY(int _y){
    y = _y;
}

FarmProduct FarmAnimal::produceEgg(){
    return FarmProduct();
}

FarmProduct FarmAnimal::produceMeat(){
    return FarmProduct();
}

FarmProduct FarmAnimal::produceMilk(){
    return FarmProduct();
}