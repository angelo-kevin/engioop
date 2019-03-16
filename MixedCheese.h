#include "SideProduct.h"

class MixedCheese : public SideProduct{
private:
  string productname;
  const int harga = 18000;
public:
  MixedCheese();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
