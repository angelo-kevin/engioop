#include "PigMeat.h"

PigMeat::PigMeat() : FarmProduct("Meat"){
  setProductName("PigMeat");
}

void PigMeat::setProductName(string name){
  this->productname = name;
}

string PigMeat::getProductName(){
  return this->productname;
}

int PigMeat::getHarga(){
  return this->harga;
}
