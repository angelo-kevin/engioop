#ifndef MIXER_H
#define MIXER_H
#include "../Facility.h"

//Mixer Class: A facility for mixing and creating various side-products for profit

class Mixer : public Facility{
    //Innate Attributes:
    bool isInRest;
    int restCountdown;
    
    //Constructor:
    public:
      Mixer();
    
    //Methods:
      void invalidateFacility();
      void facilityUpdate();
};
#endif