#include "GoatMilk.h"

GoatMilk::GoatMilk() : FarmProduct("Milk"){
  setProductName("GoatMilk");
}

void GoatMilk::setProductName(string name){
  this->productname = name;
}

string GoatMilk::getProductName(){
  return this->productname;
}

int GoatMilk::getHarga(){
  return this->harga;
}
