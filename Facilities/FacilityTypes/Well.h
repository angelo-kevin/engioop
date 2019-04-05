#ifndef WELL_H
#define WELL_H
#include "../Facility.h"

//Well Class: A facility that supplies water for player's farm

class Well : public Facility{
    //Innate Attributes:
    bool isInRest;
    int restCountdown;
    //Constructor:
    public:
      Well();
    //Methods:
      void invalidateFacility();
      void facilityUpdate();
};
#endif