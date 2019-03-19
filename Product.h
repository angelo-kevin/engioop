#ifndef PRODUCT_H
#define PRODUCT_H

#include <bits/stdc++.h>
using namespace std;

class Product{
protected:
  string tipe; //Bisa FarmProduct, bisa SideProduct
public:
  Product(string t);

  virtual int getHarga() = 0;
  virtual string getProductName() = 0;

  void setTipe(string t);
  string getTipe();
};

#endif
