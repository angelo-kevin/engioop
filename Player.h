#include<iostream>
#include<vector>
#include<string>
<<<<<<< HEAD
#include "Product/Product.h"
=======
#include "engi.h"
>>>>>>> 39f442b2147f87ad07787319d8514f706cf044dd
#include"LinkedList.h"

class Player{
    private:
        int row; //posisi x player
        int col; //posisi y player. 
        LinkedList<Product> backpack; //Menampung linkedlist of Product
        //int nell; //backpack
        int pouch; // Kantong air
    public:
        Player(); //constructor
        //~Player(); //tidak perlu 
<<<<<<< HEAD
        void Talk(Cell); //memanggil method sound dari animal
        void Interact(Cell); //memanggil method sesuai dengan apa yang ada di sekitar player
        void Kill(Cell); //destructor meatproducing animal
        void Grow(Cell); //memanggil method growGrass
        void Mix(string); //menerima parameter string yaitu side product apa yang mau dibuat. Lalu, melihat apakah backpack mempunyai bahan yang lengkap
        void setPosition(char); //set the position of player
        Cell getPosition(char); //ask for cells in 4 directions surround player
=======
        void Talk(Cell*); //memanggil method sound dari animal
        void Interact(Cell*); //memanggil method sesuai dengan apa yang ada di sekitar player
        void Kill(Cell*); //destructor meatproducing animal
        void Grow(Cell*); //memanggil method growGrass
        void Mix(string); //menerima parameter string yaitu side product apa yang mau dibuat. Lalu, melihat apakah backpack mempunyai bahan yang lengkap
        void setPosition(char); //set the position of player
        Cell* getPosition(char); //ask for Cell in 4 directions surround player
>>>>>>> 39f442b2147f87ad07787319d8514f706cf044dd

};
