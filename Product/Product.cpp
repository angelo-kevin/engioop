#include "Product.h"

Product::Product(){
  setHarga(0);
  setProductName("");
}

Product::Product(int price, string name){
  setHarga(0);
  setProductName("");
}

bool Product::operator==(Product& p){
  return getProductName() == p.getProductName();
}
void Product::setHarga(int price){
  this->harga = price;
}

void Product::setProductName(string name){
  this->productname = name;
}

int Product::getHarga(){
  return this->harga;
}

string Product::getProductName(){
  return this->productname;
}
