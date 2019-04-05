#ifndef FACILITY_H
#define FACILITY_H
#include "../Cell.h"

class Facility : public Cell{
    //Constructor:
    public:
        //Facility();
        // invalidateTruck:
        virtual void invalidateFacility(){};

        // updateFacility:
        virtual void facilityUpdate(){}
};

#endif
