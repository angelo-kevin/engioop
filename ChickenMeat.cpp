#include "ChickenMeat.h"

ChickenMeat::ChickenMeat() : FarmProduct("Meat"){
  setProductName("ChickenMeat");
}

void ChickenMeat::setProductName(string name){
  this->productname = name;
}

string ChickenMeat::getProductName(){
  return this->productname;
}

int ChickenMeat::getHarga(){
  return this->harga;
}
