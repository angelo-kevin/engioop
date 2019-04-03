#include "FarmAnimal.h"

FarmAnimal::FarmAnimal(int _x, int _y, bool l){
    x = _x;
    y = _y;
    lapar = _l;
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

bool FarmAnimal::getLapar(){
    return lapar;
} //mengecek apakah objek dari kelas ini lapar atau tidak

void FarmAnimal::revLapar(){
    lapar = !lapar;
} //mengubah nilai lapar dari objek

int FarmAnimal::getX(){
    return x;
}

int FarmAnimal::getY(){
    return y;
}