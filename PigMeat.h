#include "FarmProduct.h"

class PigMeat : public FarmProduct{
private:
  string animal;
  const int harga = 12000;
public:
  PigMeat();

  void setAnimal();
  string getAnimal();

  int getHarga();
}
