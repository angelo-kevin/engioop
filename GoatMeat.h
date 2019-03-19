#include "FarmProduct.h"

class GoatMeat : public FarmProduct{
private:
  string productname;
  const int harga = 11000;
public:
  GoatMeat();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
