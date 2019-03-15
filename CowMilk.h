#include "FarmProduct.h"

class CowMilk : public FarmProduct{
private:
  string animal;
  const int harga = 6000;
public:
  CowMilk();

  void setAnimal();
  string getAnimal();

  int getHarga();
};
