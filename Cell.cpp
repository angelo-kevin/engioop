// Base Class : Cell
/* Kelas Cell adalah base class yang merepresentasikan setiap objek-objek yang akan muncul di map, seperti semua objek Facility, objek Land, objek Farm Animal, dan Player. Kelas ini memiliki atribut symbol bertipe char yang unik bagi setiap objek di map dan method getter untuk simbol tersebut.*/

//To solve circular dependencies, include .h files at .cpp files
#include "Cell.h"
#include "Animals/FarmAnimal.h"

// Constructors:
    // Base Class Constructor
    Cell::Cell(){
        // Initialize:
        this->Symbol = '\0';
        // Make this cell unoccupied:
        this->OverrideSymbol = '\0';
        this->AnimalPtr = nullptr;
        this->FacilityPtr = nullptr;
    }

//Getters:
    // Getter for Unique symbol of every types of landtypes/facillities in cell
    char Cell::showSymbol() const{
        return this->Symbol;
    }

    // Getter for Override Symbol:
    char Cell::getOverrideSymbol() const{
        return this->OverrideSymbol;
    }

    // Getter for AnimalPtr:
    FarmAnimal* Cell::getAnimalPtr() const{
        return this->AnimalPtr;
    }

    // Getter for FacilityPtr:
    Facility* Cell::getFacilityPtr() const{
        return this->FacilityPtr;
    }   

//Setters:
    // Animal occupies cell
    void Cell::animalOccupy(FarmAnimal* _animalPtr){
        this->AnimalPtr = _animalPtr;
        this->OverrideSymbol = AnimalPtr->showSimbol();
    }

    // Player occupies cell
    void Cell::playerOccupy(){
        this->OverrideSymbol = 'P';
    }
    // Make cell unoccupied
    void Cell::makeUnoccupied(){
        this->OverrideSymbol = '\0';
    }

    // Set Facility ptr
    void Cell::setFacilityPtr(Facility* _facilityPtr){
        this->FacilityPtr = _facilityPtr;
    }
