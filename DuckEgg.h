#include "FarmProduct.h"

class DuckEgg : public FarmProduct{
private:
  string productname;
  const int harga = 3500;
public:
  DuckEgg();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
