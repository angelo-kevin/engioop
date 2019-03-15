#include "Product.h"

class FarmProduct : public Produk{
protected:
  string tipe; //Bisa egg, meat, atau milk
public:
  FarmProduct(string _tipe);

  virtual int getHarga();

  void setTipe();
  string getTipe();
}
