#include "HorseMeat.h"

HorseMeat::HorseMeat() : FarmProduct("Meat"){
  setProductName("HorseMeat");
}

void HorseMeat::setProductName(string name){
  this->productname = name;
}

string HorseMeat::getProductName(){
  return this->productname;
}

int HorseMeat::getHarga(){
  return this->harga;
}
