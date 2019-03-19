#include "EggProducing.h"
#include "MeatProducing.h"

class Chicken : public EggProducing, MeatProducing{
public:
      string Produce(); //menghasilkan 'telur' dan 'daging'
      void Sound(); //suara 'petok'
};
