#include "FarmProduct.h"

class HorseMeat : public FarmProduct{
private:
  string productname;
  const int harga = 15000;
public:
  HorseMeat();

  void setProductName(string name);
  string getProductName();

  int getHarga();
};
