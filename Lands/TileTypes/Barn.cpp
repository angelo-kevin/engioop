#include "Barn.h"
/* Kelas Barn adalah turunan dari kelas Land dan merepresentasikan lahan pijakan yang di dalam kandang dan MeatProducing Animals.*/
// Constructor Implementation:
Barn::Barn(){
    this->Symbol = 'x';
}
//Method to grow grass chaange symbol into '#'':
void Barn::growGrass(){
    this->Symbol = '@';
}
