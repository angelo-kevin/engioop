#Bashscripts to compile ctest and run it:

g++ \
Cell.cpp \
common.cpp \
Lands/TileTypes/Barn.cpp \
Lands/TileTypes/Grassland.cpp \
Lands/TileTypes/Coop.cpp \
Facilities/FacilityTypes/Mixer.cpp \
Facilities/FacilityTypes/Well.cpp \
Facilities/FacilityTypes/Truck.cpp \
Animals/FarmAnimal.cpp \
Animals/MeatProducing.cpp \
Animals/EggProducing.cpp \
Animals/MilkProducing.cpp \
Animals/Chicken.cpp \
Animals/Cow.cpp \
Animals/Duck.cpp \
Animals/Goat.cpp \
Animals/Horse.cpp \
Animals/Pig.cpp \
Product/FarmProduct.cpp \
Product/Product.cpp \
Product/SideProduct.cpp \
Product/FarmProduct/ChickenEgg.cpp \
Product/FarmProduct/ChickenMeat.cpp \
Product/FarmProduct/CowMeat.cpp \
Product/FarmProduct/CowMilk.cpp \
Product/FarmProduct/DuckEgg.cpp \
Product/FarmProduct/DuckMeat.cpp \
Product/FarmProduct/GoatMeat.cpp \
Product/FarmProduct/GoatMilk.cpp \
Product/FarmProduct/HorseMeat.cpp \
Product/FarmProduct/PigMeat.cpp \
Product/SideProduct/BaconOmelette.cpp \
Product/SideProduct/HorseRolade.cpp \
Product/SideProduct/MixedCheese.cpp \
Player.cpp \
Tests/CTest.cpp \
-L/usr/lib/ -lgtest -lgtest_main -pthread -o engiMoonTest

./engiMoonTest