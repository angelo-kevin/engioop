#include "FarmProduct.h"

class CowMilk : public FarmProduct{
private:
  string productname;
  const int harga = 6000;
public:
  CowMilk();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
