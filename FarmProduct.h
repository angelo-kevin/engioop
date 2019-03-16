#ifndef FARMPRODUCT_H
#define FARMPRODUCT_H

#include "Product.h"

class FarmProduct : public Product{
protected:
  string tipe; //Bisa egg, meat, atau milk
public:
  FarmProduct(string _tipe);

  void setTipe(string _tipe);
  string getTipe();
};

#endif
