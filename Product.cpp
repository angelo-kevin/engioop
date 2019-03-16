#include "Product.h"

Product::Product(string t){
  setTipe(t);
}

void Product::setTipe(string t){
  this->tipe = t;
}

string Product::getTipe(){
  return this->tipe;
}
