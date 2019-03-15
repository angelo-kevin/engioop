#include "Product.h"

class FarmProduct : public Product{
protected:
  string tipe; //Bisa egg, meat, atau milk
public:
  FarmProduct(string _tipe);

  virtual int getHarga();

  void setTipe();
  string getTipe();
};
