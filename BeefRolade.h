#include "SideProduct.h"

class BeefRolade : public SideProduct{
private:
  string productname;
  const int harga = 25000;
public:
  BeefRolade();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
