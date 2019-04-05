#include "Mixer.h"

//Mixer Class: A facility for mixing and creating various side-products for profit

//Constructor implementation:
Mixer::Mixer(){
    this->Symbol = 'M';
}

//Make Mixer Invalid:
void Mixer::invalidateFacility(){
    this->Symbol = 'm';
    this->isInRest = true;
    this->restCountdown = 2;
}

//Status update for truck:
void Mixer::facilityUpdate(){
    if(this->isInRest){
        this->restCountdown--;
        if(this->restCountdown == 0){
            this->isInRest = false;
            this->Symbol = 'M';
        }
    }
}