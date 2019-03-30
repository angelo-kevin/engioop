#include "Coop.h"
/*Kelas Coop adalah turunan dari kelas Land dan merepresentasikan lahan pijakan yang di dalam kandang EggProducing Animals.*/

// Constructor Implementation:
Coop::Coop(){
    this->Symbol = 'o';
}
//Method to grow grass chaange symbol into '#'':
void Coop::growGrass(){
    this->Symbol = '*';
}

