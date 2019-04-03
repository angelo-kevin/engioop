
#include "Grassland.h"
/*Kelas Coop adalah turunan dari kelas Land dan merepresentasikan lahan pijakan yang di dalam kandang EggProducing Animals.*/

// Constructor Implementation:
Grassland::Grassland(){
    this->Symbol = '.';
}

//Method to grow grass chaange symbol into '#'':
void Grassland::growGrass(){
    this->Symbol = '#';
}

//Method to ungrow grass chaange symbol into '.':
void Grassland::ungrowGrass(){
    this->Symbol = '.';
}
