#include "FarmProduct.h"

class DuckEgg : public FarmProduct{
private:
  string animal;
  const int harga = 3500;
public:
  DuckEgg();

  void setAnimal();
  string getAnimal();

  int getHarga();
}
