#include "FarmProduct.h"

class GoatMilk : public FarmProduct{
private:
  string animal;
  const int harga = 8000;
public:
  GoatMilk();

  void setAnimal();
  string getAnimal();

  int getHarga();
};
