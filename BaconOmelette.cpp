#include "BaconOmelette.h"

BaconOmelette::BaconOmelette() : SideProduct(){
  setProductName("BaconOmelette");
}

void BaconOmelette::setProductName(string name){
  this->productname = name;
}

string BaconOmelette::getProductName(){
  return this->productname;
}

int BaconOmelette::getHarga(){
  return this->harga;
}
