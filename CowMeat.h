#include "FarmProduct.h"

class CowMeat : public FarmProduct{
private:
  string productname;
  const int harga = 15000;
public:
  CowMeat();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
