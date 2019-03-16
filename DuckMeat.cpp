#include "DuckMeat.h"

DuckMeat::DuckMeat() : FarmProduct("Meat"){
  setProductName("DuckMeat");
}

void DuckMeat::setProductName(string name){
  this->productname = name;
}

string DuckMeat::getProductName(){
  return this->productname;
}

int DuckMeat::getHarga(){
  return this->harga;
}
