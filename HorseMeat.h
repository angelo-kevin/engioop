#include "FarmProduct.h"

class HorseMeat : public FarmProduct{
private:
  string animal;
  const int harga = 15000;
public:
  HorseMeat();

  void setAnimal();
  string getAnimal();

  int getHarga();
};
