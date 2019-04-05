#ifndef TRUCK_H
#define TRUCK_H
#include "../Facility.h"

//Truck Class: A facility for shipping various products from player's farm

class Truck : public Facility{
    //Innate Attributes:
    bool isInRest;
    int restCountdown;

    //Constructor:
    public:
        Truck();
    //Methods:
        //Make Unused:
        void invalidateTruck();
        void truckStatusUpdate();
};
#endif