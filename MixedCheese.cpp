#include "MixedCheese.h"

MixedCheese::MixedCheese() : SideProduct(){
  setProductName("MixedCheese");
}

void MixedCheese::setProductName(string name){
  this->productname = name;
}

string MixedCheese::getProductName(){
  return this->productname;
}

int MixedCheese::getHarga(){
  return this->harga;
}
