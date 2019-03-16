#include "FarmProduct.h"

FarmProduct::FarmProduct(string _tipe) : Product("FarmProduct"){
  setTipe(_tipe);
}

void FarmProduct::setTipe(string _tipe){
  this->tipe = _tipe;
}

string FarmProduct::getTipe(){
  return this->tipe;
}
