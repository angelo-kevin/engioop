#include "FarmProduct.h"

class DuckMeat : public FarmProduct{
private:
  string productname;
  const int harga = 13000;
public:
  DuckMeat();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
