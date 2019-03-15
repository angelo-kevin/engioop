#include "FarmProduct.h"

class ChickenEgg : public FarmProduct{
private:
  string animal;
  const int harga = 2000;
public:
  ChickenEgg();

  void setAnimal();
  string getAnimal();

  int getHarga();
};
