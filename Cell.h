#ifndef CELL_H
#define CELL_H

//#include "Animals/FarmAnimal.h"
//#include "Animals/FarmAnimal.cpp"

//Forward Declaration:
class FarmAnimal;
class Facility;

// Base Class : Cell
/* Kelas Cell adalah base class yang merepresentasikan setiap objek-objek yang akan muncul di map, seperti semua objek Facility, objek Land, objek Farm Animal, dan Player. Kelas ini memiliki atribut symbol bertipe char yang unik bagi setiap objek di map dan method getter untuk simbol tersebut.*/
class Cell{
  protected:
    // Unique symbol for each objects
    char Symbol;
    char OverrideSymbol;
    FarmAnimal* AnimalPtr;
    Facility* FacilityPtr;

  public:
    // Constructors:
      // Base Class Constructor
      Cell();

    //Getters:
      // Method to show Unique symbol for every types of objects in cell
      char showSymbol() const;

      // Get the OverrideSymbol;
      char getOverrideSymbol() const;

      // Get the AnimalPointers;
      FarmAnimal* getAnimalPtr() const;

      // Get Facility Ptr:
      Facility* getFacilityPtr() const;

    //Setters:
      // Occupy the spot in map with an animal:
      void animalOccupy(FarmAnimal*);

      // Make cell unoccupied:
      void makeUnoccupied();

      // Occupy the spot in map with the player:
      void playerOccupy();

      // Set facility ptr:
      void setFacilityPtr(Facility* _facilityPtr);

      // Make grass grow:
      virtual void growGrass(){};

      // Ungrow the grass:
      virtual void ungrowGrass(){};

      // invalidateTruck:
      virtual void invalidateTruck(){};

      // updateFacility:
      virtual void updateFacility(){}
};
#endif