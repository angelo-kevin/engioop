#include<iostream>
#include<vector>
#include<string>
#include"Product.h"
#include "Landtypes.h"
#include "cells.h"

class Player{
    private:
        private:
        int row;
        int col;
        vector<Product> backpack;
        //int nell; //backpack
        int pouch; // water
    public:
        Player();
        ~Player();
        void Talk(Cells*);
        void Interact(Cells*);
        void Kill(Cells*);
        void Grow(Cells*);
        void Mix(string);
        void classIdentifier(char c, vector<Cells*> &v);
        void setPosition(char);
        Cells* getPosition(char); //ask for position in 4 directions
        void loadMap();

};
