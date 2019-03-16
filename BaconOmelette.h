#include "SideProduct.h"

class BaconOmelette : public SideProduct{
private:
  string productname;
  const int harga = 18000;
public:
  BaconOmelette();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
