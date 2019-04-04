// C-TEST FOR: Cell.cpp
#include "../Cell.h"
#include "../Lands/TileTypes/Barn.h"
#include "../Lands/TileTypes/Grassland.h"
#include "../Lands/TileTypes/Coop.h"
#include "../Facilities/FacilityTypes/Mixer.h"
#include "../Facilities/FacilityTypes/Well.h"
#include "../Facilities/FacilityTypes/Truck.h"
#include "../Animals/Chicken.h"
#include <gtest/gtest.h>

//Cell: 
    TEST(CellTest, test1) {
        Cell* temp =  new Cell(); 
        ASSERT_NE(nullptr, temp);
        ASSERT_EQ(temp->getOverrideSymbol(), '\0');
        temp->playerOccupy();
        ASSERT_EQ(temp->getOverrideSymbol(), '!');
        //Check land symbol:
        temp = new Barn();
        ASSERT_EQ(temp->showSymbol(), 'x');
        //Check occupy animal:
        Chicken* chickenPtr = new Chicken(1,1,true);
        temp->animalOccupy(chickenPtr);
        ASSERT_EQ(temp->getOverrideSymbol(), 'c');
        //Check unoccupied:
        temp->makeUnoccupied();
        ASSERT_EQ(temp->getOverrideSymbol(), '\0');
        //Delete pointers:
        delete temp;
        delete chickenPtr;
    }

//Lands:
    //TileTypes:
        TEST(BarnTest, test2) {
            Barn* temp = new Barn();
            ASSERT_EQ(temp->showSymbol(), 'x');
            temp->growGrass();
            ASSERT_EQ(temp->showSymbol(), '@');
            temp->ungrowGrass();
            ASSERT_EQ(temp->showSymbol(), 'x');
        }

        TEST(CoopTest, test3) {
            Coop* temp = new Coop();
            ASSERT_EQ(temp->showSymbol(), 'o');
            temp->growGrass();
            ASSERT_EQ(temp->showSymbol(), '*');
            temp->ungrowGrass();
            ASSERT_EQ(temp->showSymbol(), 'o');
        }

        TEST(GrasslandTest, test4) {
            Grassland* temp = new Grassland();
            ASSERT_EQ(temp->showSymbol(), '.');
            temp->growGrass();
            ASSERT_EQ(temp->showSymbol(), '#');
            temp->ungrowGrass();
            ASSERT_EQ(temp->showSymbol(), '.');
        }

    //Facilities:
        TEST(MixerTest, test5) {
            Mixer* temp = new Mixer();
            ASSERT_EQ(temp->showSymbol(), 'M');
        }

        TEST(WellTest, test6) {
            Well* temp = new Well();
            ASSERT_EQ(temp->showSymbol(), 'W');
        }

        TEST(TruckTest, test7) {
            Truck* temp = new Truck();
            ASSERT_EQ(temp->showSymbol(), 'T');
        }

// RUN TESTS:
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}