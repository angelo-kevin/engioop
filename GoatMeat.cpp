#include "GoatMeat.h"

GoatMeat::GoatMeat() : FarmProduct("Meat"){
  setProductName("GoatMeat");
}

void GoatMeat::setProductName(string name){
  this->productname = name;
}

string GoatMeat::getProductName(){
  return this->productname;
}

int GoatMeat::getHarga(){
  return this->harga;
}
