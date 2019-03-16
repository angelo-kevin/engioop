#include "CowMilk.h"

CowMilk::CowMilk() : FarmProduct("Milk"){
  setProductName("CowMilk");
}

void CowMilk::setProductName(string name){
  this->productname = name;
}

string CowMilk::getProductName(){
  return this->productname;
}

int CowMilk::getHarga(){
  return this->harga;
}
