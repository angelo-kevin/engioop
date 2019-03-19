#include "ChickenEgg.h"

ChickenEgg::ChickenEgg() : FarmProduct("Egg"){
  setProductName("ChickenEgg");
}

void ChickenEgg::setProductName(string name){
  this->productname = name;
}

string ChickenEgg::getProductName(){
  return this->productname;
}

int ChickenEgg::getHarga(){
  return this->harga;
}
