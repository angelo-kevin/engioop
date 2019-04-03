#include<iostream>
#include<vector>
#include<string>
#include "engi.h"
#include "LinkedList.h"
#include "common.h"


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
        void Talk(char); //memanggil method sound dari animal
        void Interact(char); //memanggil method sesuai dengan apa yang ada di sekitar player
        void Kill(char); //destructor meatproducing animal
        void Grow(char); //memanggil method growGrass
        void Mix(char, string); //menerima parameter string yaitu side product apa yang mau dibuat. Lalu, melihat apakah backpack mempunyai bahan yang lengkap
        Cell* getPosition(char, int*, int*); //ask for Cell in 4 directions surround player
        void setPosition(char); //set the position of player

};
