#include "CowMeat.h"

CowMeat::CowMeat() : FarmProduct("Meat"){
  setProductName("CowMeat");
}

void CowMeat::setProductName(string name){
  this->productname = name;
}

string CowMeat::getProductName(){
  return this->productname;
}

int CowMeat::getHarga(){
  return this->harga;
}
