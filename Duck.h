#include "EggProducing.h"
#include "MeatProducing.h"

class Duck : public EggProducing, MeatProducing{
public:
      string Produce(); //menghasilkan 'telur' dan 'daging'
      void Sound(); //suara 'petok'
};
