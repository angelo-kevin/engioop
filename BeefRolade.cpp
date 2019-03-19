#include "BeefRolade.h"

BeefRolade::BeefRolade() : SideProduct(){
  setProductName("BeefRolade");
}

void BeefRolade::setProductName(string name){
  this->productname = name;
}

string BeefRolade::getProductName(){
  return this->productname;
}

int BeefRolade::getHarga(){
  return this->harga;
}
