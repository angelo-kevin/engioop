#include<iostream>
#include<vector>
#include<string>
#include "Product/Product.h"
#include"LinkedList.h"
#include "Cell.h"

class Player : Cell{
    private:
        int row; //posisi x player
        int col; //posisi y player. 
        LinkedList<Product> backpack; //Menampung linkedlist of Product
        //int nell; //backpack
        int pouch; // Kantong air
    public:
        Player(); //constructor
        //~Player(); //tidak perlu 
        void Talk(Cell); //memanggil method sound dari animal
        void Interact(Cell); //memanggil method sesuai dengan apa yang ada di sekitar player
        void Kill(Cell); //destructor meatproducing animal
        void Grow(Cell); //memanggil method growGrass
        void Mix(string); //menerima parameter string yaitu side product apa yang mau dibuat. Lalu, melihat apakah backpack mempunyai bahan yang lengkap
        void setPosition(char); //set the position of player
        Cell getPosition(char); //ask for cells in 4 directions surround player

};
