#include "FarmProduct.h"

class GoatMilk : public FarmProduct{
private:
  string productname;
  const int harga = 8000;
public:
  GoatMilk();

  void setProductName(string name);
  string getproductname();

  int getHarga();
};
