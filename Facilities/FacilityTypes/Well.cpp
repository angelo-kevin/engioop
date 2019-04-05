#include "Well.h"

//Well Class: A facility that supplies water for player's farm

//Constructor implementation:
Well::Well(){
    this->Symbol = 'W';
    this->isInRest = false;
    this->restCountdown = 0;
}

//Make Well Invalid:
void Well::invalidateFacility(){
    this->Symbol = 'w';
    this->isInRest = true;
    this->restCountdown = 5;
}

//Status update for Well:
void Well::facilityUpdate(){
    if(this->isInRest){
        this->restCountdown--;
        if(this->restCountdown == 0){
            this->isInRest = false;
            this->Symbol = 'W';
        }
    }
}