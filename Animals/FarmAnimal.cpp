#include "FarmAnimal.h"

FarmAnimal::FarmAnimal(int _x, int _y, bool l){
    x = _x;
    y = _y;
    lapar = l;
} //ctor

//Getter setter
char FarmAnimal::showSimbol(); //mengembalikan nilai simbol
void FarmAnimal::revSimbol(); //mengubah nilai simbol dari objek yang akan ditunjukkan di map
int FarmAnimal::getThreshold(); //mengembalikan nilai threshold dari objek
bool FarmAnimal::getLapar(); //mengecek apakah objek dari kelas ini lapar atau tidak
void FarmAnimal::setLapar(); //mengubah nilai lapar dari objek
int FarmAnimal::getX();
int FarmAnimal::getY();