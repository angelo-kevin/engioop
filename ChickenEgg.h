#include "FarmProduct.h"

class ChickenEgg : public FarmProduct{
private:
  string productname;
  const int harga = 2000;
public:
  ChickenEgg();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
