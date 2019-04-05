#include "Truck.h"

//Truck Class: A facility for shipping various products from player's farm

//Constructor implementation:
Truck::Truck(){
    this->Symbol = 'T';
    this->isInRest = false;
    this->restCountdown = 0;
}

//Make Truck Invalid:
void Truck::invalidateFacility(){
    this->Symbol = 't';
    this->isInRest = true;
    this->restCountdown = 8;
}

//Status update for truck:
void Truck::facilityUpdate(){
    if(this->isInRest){
        this->restCountdown--;
        if(this->restCountdown == 0){
            this->isInRest = false;
            this->Symbol = 'T';
        }
    }
}