#include "MilkProducing.h"
#include "MeatProducing.h"

class Goat : public MilkProducing, MeatProducing{
public:
      string Produce(); //menghasilkan 'susu' dan 'daging'
      void Sound(); //suara 'petok'
};
