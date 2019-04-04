// C-TEST FOR: Cell.cpp
#include "../Cell.h"
#include "../Lands/TileTypes/Barn.h"
#include "../Lands/TileTypes/Grassland.h"
#include "../Lands/TileTypes/Coop.h"
#include "../Facilities/FacilityTypes/Mixer.h"
#include "../Facilities/FacilityTypes/Well.h"
#include "../Facilities/FacilityTypes/Truck.h"
#include "../Animals/Chicken.h"
#include "../Animals/FarmAnimal.h"
#include "../Animals/Cow.h"
#include "../Animals/Duck.h"
#include "../Animals/Goat.h"
#include "../Animals/Horse.h"
#include "../Animals/Pig.h"
#include <gtest/gtest.h>

//Cell: 
    TEST(CellTest, test1) {
        Cell* temp =  new Cell(); 
        ASSERT_NE(nullptr, temp);
        ASSERT_EQ(temp->getOverrideSymbol(), '\0');
        temp->playerOccupy();
        ASSERT_EQ(temp->getOverrideSymbol(), 'P');
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

        TEST(ChickenTest, test8){
            Chicken chick = Chicken(2,5,true);
            ASSERT_EQ(chick.getLapar(),true);
            ASSERT_EQ(chick.getThreshold(),8);
            ASSERT_EQ(chick.getX(),2);
            ASSERT_EQ(chick.getY(),5);
            chick.minThreshold();
            ASSERT_EQ(chick.getThreshold(),7);
            FarmProduct prod = chick.produceEgg();
            ASSERT_EQ(prod.getProductName(),"ChickenEgg");
            FarmProduct prodx = chick.produceMilk();
            ASSERT_EQ(prodx.getProductName(),"");
            ASSERT_EQ(chick.showSimbol(),'c');
            chick.revLapar();
            ASSERT_EQ(chick.getLapar(),false);
        }

        TEST(CowTest, test9){
            Cow cow = Cow(1,4,true);
            ASSERT_EQ(cow.getLapar(),true);
            ASSERT_EQ(cow.getThreshold(),10);
            ASSERT_EQ(cow.getX(),1);
            ASSERT_EQ(cow.getY(),4);
            cow.minThreshold();
            ASSERT_EQ(cow.getThreshold(),9);
            FarmProduct prod = cow.produceMilk();
            ASSERT_EQ(prod.getProductName(),"CowMilk");
            FarmProduct prodx = cow.produceEgg();
            ASSERT_EQ(prodx.getProductName(),"");
            ASSERT_EQ(cow.showSimbol(),'s');
            cow.revLapar();
            ASSERT_EQ(cow.getLapar(),false);
        }

        TEST(DuckTest, test10){
            Duck duck = Duck(10,8,false);
            ASSERT_EQ(duck.getLapar(),false);
            ASSERT_EQ(duck.getThreshold(),8);
            ASSERT_EQ(duck.getX(),10);
            ASSERT_EQ(duck.getY(),8);
            duck.minThreshold();
            ASSERT_EQ(duck.getThreshold(),7);
            FarmProduct prod = duck.produceEgg();
            ASSERT_EQ(prod.getProductName(),"DuckEgg");
            FarmProduct prodx = duck.produceMilk();
            ASSERT_EQ(prodx.getProductName(),"");
            ASSERT_EQ(duck.showSimbol(),'D');
            duck.revLapar();
            ASSERT_EQ(duck.getLapar(),true);
        }

        TEST(GoatTest, test11){
            Goat goat = Goat(3,7,false);
            ASSERT_EQ(goat.getLapar(),false);
            ASSERT_EQ(goat.getThreshold(),10);
            ASSERT_EQ(goat.getX(),3);
            ASSERT_EQ(goat.getY(),7);
            goat.minThreshold();
            ASSERT_EQ(goat.getThreshold(),9);
            FarmProduct prod = goat.produceMilk();
            ASSERT_EQ(prod.getProductName(),"GoatMilk");
            FarmProduct prodx = goat.produceEgg();
            ASSERT_EQ(prodx.getProductName(),"");
            ASSERT_EQ(goat.showSimbol(),'G');
            goat.revLapar();
            ASSERT_EQ(goat.getLapar(),true);
        }

        TEST(HorseTest, test12){
            Horse horse = Horse(8,5,true);
            ASSERT_EQ(horse.getLapar(),true);
            ASSERT_EQ(horse.getThreshold(),12);
            ASSERT_EQ(horse.getX(),8);
            ASSERT_EQ(horse.getY(),5);
            horse.minThreshold();
            ASSERT_EQ(horse.getThreshold(),11);
            FarmProduct prod = horse.produceMeat();
            ASSERT_EQ(prod.getProductName(),"HorseMeat");
            FarmProduct prodx = horse.produceMilk();
            ASSERT_EQ(prodx.getProductName(),"");
            ASSERT_EQ(horse.showSimbol(),'h');
            horse.revLapar();
            ASSERT_EQ(horse.getLapar(),false);
        }

        TEST(PigTest, test13){
            Pig pig = Pig(4,4,false);
            ASSERT_EQ(pig.getLapar(),false);
            ASSERT_EQ(pig.getThreshold(),12);
            ASSERT_EQ(pig.getX(),4);
            ASSERT_EQ(pig.getY(),4);
            pig.minThreshold();
            ASSERT_EQ(pig.getThreshold(),11);
            FarmProduct prod = pig.produceMeat();
            ASSERT_EQ(prod.getProductName(),"PigMeat");
            FarmProduct prodx = pig.produceMilk();
            ASSERT_EQ(prodx.getProductName(),"");
            ASSERT_EQ(pig.showSimbol(),'B');
            pig.revLapar();
            ASSERT_EQ(pig.getLapar(),true);
        }

// RUN TESTS:
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}