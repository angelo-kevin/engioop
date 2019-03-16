#include "FarmProduct.h"

class ChickenMeat : public FarmProduct{
private:
  string productname;
  const int harga = 10000;
public:
  ChickenMeat();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
