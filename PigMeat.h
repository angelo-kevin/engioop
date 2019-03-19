#include "FarmProduct.h"

class PigMeat : public FarmProduct{
private:
  string productname;
  const int harga = 12000;
public:
  PigMeat();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
