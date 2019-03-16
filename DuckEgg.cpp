#include "DuckEgg.h"

DuckEgg::DuckEgg() : FarmProduct("Egg"){
  setProductName("DuckEgg");
}

void DuckEgg::setProductName(string name){
  this->productname = name;
}

string DuckEgg::getProductName(){
  return this->productname;
}

int DuckEgg::getHarga(){
  return this->harga;
}
