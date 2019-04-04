#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <ctype.h>
#include "Cell.h"
//Include Map:
#include "common.h"
//For Transform:
#include <algorithm>

#include "Lands/Land.h"
#include "Facilities/Facility.h"

//tile-types:
#include "Lands/TileTypes/Barn.h"
#include "Lands/TileTypes/Grassland.h"
#include "Lands/TileTypes/Coop.h"
/*
#include "Lands/TileTypes/Barn.cpp"
#include "Lands/TileTypes/Grassland.cpp"
#include "Lands/TileTypes/Coop.cpp"
*/
//facility-types:
#include "Facilities/FacilityTypes/Mixer.h"
#include "Facilities/FacilityTypes/Well.h"
#include "Facilities/FacilityTypes/Truck.h"
/*
#include "Facilities/FacilityTypes/Mixer.cpp"
#include "Facilities/FacilityTypes/Well.cpp"
#include "Facilities/FacilityTypes/Truck.cpp"
*/
//Animal-types:
#include "Animals/FarmAnimal.h"
#include "Animals/Pig.h"
#include "Animals/Chicken.h"

//Player:
#include "Player.h"

//Product:
#include "Product/Product.h"

//Miscellaneous Library:
#include <unistd.h>

#define maxsize 256
using namespace std;

#include <cstdlib>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

//GLOBAL VARIABLES:
#include "common.h"
//vector<vector<Cell*> > gamemap;

//FUNCTIONS:

void classIdentifier(char c, vector<Cell*> &v){
    //ALSO PUTS IT INTO VECTHOR
    if (c == '.'){
        v.push_back(new Grassland());
    }
    else if (c == '#'){
        Grassland* temp = new Grassland();
        temp->growGrass();
        v.push_back(temp);
    }
    else if (c == '@'){
        Barn* temp = new Barn();
        temp->growGrass();
        v.push_back(temp);
    }
    else if (c == '*'){
        Coop* temp = new Coop();
        temp->growGrass();
        v.push_back(temp);
    }
    else if (c == 'o'){
        v.push_back(new Coop());
    }
    else if (c == 'x'){
        v.push_back(new Barn());
    }
    else if (c == 'T'){
        v.push_back(new Truck());
    }
    else if (c == 'W'){
        v.push_back(new Well());
    }
    else if (c == 'M'){
        v.push_back(new Mixer());
    }
}

void loadMap(){
    ifstream mapfile;
    string line;
    int idx;
    vector<Cell*> tempv;
    mapfile.open ("mapschema.txt");
    if (mapfile.is_open())
    {
        while (getline(mapfile,line) )
        {
            idx=0;
            while(line[idx] != '\0'){
                classIdentifier(line[idx], tempv);
                //cout<<tempv[idx]->showSymbol()<<endl;
                idx++;
            }
            gamemap.push_back(tempv);
            tempv.clear();
        }
    }

    else cout << "File read error, you fucking shit";
    mapfile.close();
}

void printMap(){
    vector< vector<Cell*> >::iterator row;
    vector<Cell*>::iterator col;
    int colMax = gamemap[0].size();
    for(int i = 0; i < colMax * 4 - 15; i++){
      if(i == (colMax * 4 + 1) / 2){
        cout << "PETA ENGI'S FARM";
      } else{
        cout << " ";
      }
    }
    cout<<endl;

    for(int i = 0; i < colMax * 4 + 1; i++){
      cout << "_";
    }

    cout << "" << endl;
    for (row = gamemap.begin(); row != gamemap.end(); row++) {
        cout << "| ";
        for (col = row->begin(); col != row->end(); col++) {
            // Check whether this paticular cell is occupied or not:
            if ((*col)->getOverrideSymbol()  ==  '\0')
                // If unoccupied:
                cout<<(*col)->showSymbol() << " | ";
            else
                // If occupied:
                cout<<(*col)->getOverrideSymbol() << " | ";
        }
        cout<<endl;
    }

    for(int i = 0; i < colMax * 4 + 1; i++){
      if(i % 4 == 0){
        cout << "|";
      } else{
        cout << "-";
      }
    }
    cout << "" << endl;

    int moneySpaces = 6; //ganti dengan jumlah digit money

    for(int i = 0; i < colMax * 4; i++){
      if(i == 0){
        cout << "| Money: " << 123456;
      } else if(i >= 9 + moneySpaces){
        cout << " ";
      }
    }
    cout << "|" << endl;

    for(int i = 0; i < colMax * 4 + 1; i++){
      if(i == 0 || i == colMax * 4){
        cout << "|";
      } else{
        cout << "_";
      }
    }
    cout << "" << endl;

    int waterSpaces = 3;
    for(int i = 0; i < colMax * 4; i++){
      if(i == 0){
        cout << "| Water: " << 100;
      } else if(i >= 9 + waterSpaces){
        cout << " ";
      }
    }
    cout << "|" << endl;

    for(int i = 0; i < colMax * 4 + 1; i++){
      if(i == 0 || i == colMax * 4){
        cout << "|";
      } else{
        cout << "_";
      }
    }
    cout << "" << endl;
}

void printLegend(){
  cout << "Keterangan: " << endl;
  cout << "C: Ayam" << endl;
  cout << "B: Babi" << endl;
  cout << "D: Bebek" << endl;
  cout << "G: Kambing" << endl;
  cout << "H: Kuda" << endl;
  cout << "S: Sapi" << endl;
  cout << "T: Truck" << endl;
  cout << "M: Mixer" << endl;
  cout << "W: Well" << endl;
  cout << endl;
  cout << "P: Player" << endl;
  cout << endl;
  cout << ". : Grassland" << endl;
  cout << "x : Barn" << endl;
  cout << "o : Coop" << endl;
  cout << endl;
  cout << "*,@,# : Rumput" << endl;
}

int main(){
    system(CLEAR);
    cout << " _____            _ _      ______                   " << endl;
    cout << "|  ___|          (_| )     |  ___|                  " << endl;
    cout << "| |__ _ __   __ _ _|/ ___  | |_ __ _ _ __ _ __ ___  " << endl;
    cout << "|  __| '_ \\ / _` | | / __| |  _/ _` | '__| '_ ` _ \\ " << endl;
    cout << "| |__| | | | (_| | | \\__ \\ | || (_| | |  | | | | | |" << endl;
    cout << "\\____/_| |_|\\__, |_| |___/ \\_| \\__,_|_|  |_| |_| |_|" << endl;
    cout << "             __/ |                                  " << endl;
    cout << "            |___/                                   " << endl;
    cout << "Enter any key to start" << endl;
    string command = "";
    cout << "> ";
    cin >> command;
    cout << endl;

    loadMap();

    system(CLEAR);
    FarmAnimal* a1 = new Pig(2, 2, false);
    // cout << a1->produceMeat().getProductName() << endl;

    gamemap[0][0]->growGrass();
    gamemap[1][0]->growGrass();
    //gamemap[0][0]->animalOccupy(a1);

    FarmAnimal* a2 = new Chicken(1,5,true);
    gamemap[a2->getX()][a2->getY()]->animalOccupy(a2);

    printMap();

    printLegend();

    cout << "Inventory: " << endl;
    cout << "" << endl;

    //Construct Player:
    Player mainPlayer(5,5);
    gamemap[mainPlayer.getX()][mainPlayer.getY()]->playerOccupy();

    while(command != "exit"){
      //system(CLEAR);
      cout<< a2->getX() << endl;
      cout<< a2->getY() << endl;

      printMap();

      cout << "Command: ";
      cout << "" << endl;

      cin >> command;
      transform(command.begin(), command.end(), command.begin(), ::tolower);
      cout << command;
      if(command == "talk"){
        cout << "talk" << endl;
        char c;
        cin>>c;
        mainPlayer.Talk(c);
      } else if(command == "interact"){
        cout << "interact" << endl;
      } else if(command == "kill"){
        cout << "kill" << endl;
      } else if(command == "grow"){
        cout << "grow" << endl;
      } else if(command == "mix"){
        cout << "mix" << endl;
      } else if(command == "n" || command == "w" || command == "e" || command == "s"){
        gamemap[mainPlayer.getY()][mainPlayer.getX()]->makeUnoccupied();
        printMap();
        mainPlayer.setPosition(command[0]);
        printMap();
        gamemap[mainPlayer.getY()][mainPlayer.getX()]->playerOccupy();
        printMap();
      }else{
        cout << "Invalid command" << endl;
      }


    //Construct Player:
    // Player mainPlayer(5,5);
    // gamemap[mainPlayer.getX()][mainPlayer.getY()]->playerOccupy();
    //
    // while(command != "exit"){
    //   //system(CLEAR);
    //   cout<< a2->getX() << endl;
    //   cout<< a2->getY() << endl;
    //
    //   printMap();
    //
    //   cout << "Command: ";
    //   cout << "" << endl;
    //
    //   cin >> command;
    //   transform(command.begin(), command.end(), command.begin(), ::tolower);
    //   cout << command;
    //   if(command == "talk"){
    //     cout << "talk" << endl;
    //     char c;
    //     cin>>c;
    //     mainPlayer.Talk(c);
    //   } else if(command == "interact"){
    //     cout << "interact" << endl;
    //   } else if(command == "kill"){
    //     cout << "kill" << endl;
    //   } else if(command == "grow"){
    //     cout << "grow" << endl;
    //   } else if(command == "mix"){
    //     cout << "mix" << endl;
    //   } else if(command == "n" || command == "w" || command == "e" || command == "s"){
    //     gamemap[mainPlayer.getY()][mainPlayer.getX()]->makeUnoccupied();
    //     printMap();
    //     mainPlayer.setPosition(command[0]);
    //     printMap();
    //     gamemap[mainPlayer.getY()][mainPlayer.getX()]->playerOccupy();
    //     printMap();
    //   }else{
    //     cout << "Invalid command" << endl;
    //   }
    //
    //   cout << "Output: " << endl;
    //   cout << "" << endl;
    //
    //   //sleep(2000);
    // }
      //sleep(2000);
    }
      /*animul1* a = new animul1();
      gamemap.push_back(a);
      gamemap.push_back(new animul1());
      gamemap.push_back(new animul2());
      cout<<((gamemap.at(0))->showSymbol())<<endl;
      //CREATE MAP:
      //gamemap[0][0]->growGrass();
      //gamemap[1][0]->growGrass();
      // FarmAnimal* a1 = new Pig(2, 2, false);
      // gamemap[0][0]->animalOccupy(a1);
      // FarmAnimal* a2 = new Chicken(true, 2, 2);
      // gamemap[2][2]->animalOccupy(a2);
      // printLine();
      // printLine();
      // gamemap[0][0]-> makeUnoccupied();
      // printMap();
      // cout<< gamemap[0][0]-> getAnimalPtr()->sound() << endl;
      //Player p;
      //p.Interact(gamemap[0][0]);
    }*/
}


/*
class animul1: public Cell{
    private:
        char* namu;
    public:
        animul1(){
            namu = new char[maxsize];
            strcpy(namu, "SHIT");
        }
        animul1(char* neemu){
            namu = new char[maxsize];
            strcpy(namu, neemu);
        }
        virtual ~animul1(){
            delete[] namu;
        }
        char showSymbol(){
            return 'a';
        }
};
class animul2: public Cell{
    private:
        char* namu;
    public:
        animul2(){
            namu = new char[maxsize];
            strcpy(namu, "SHIT");
            //strcpy(namu, "SHIT");
        }
        animul2(char* neemu){
            namu = new char[maxsize];
            strcpy(namu, neemu);
        }
        virtual ~animul2(){
            delete[] namu;
        }
        char showSymbol(){
            return 'a';
        }
};
class Player{
    private:
        int x;
        int y;
    public:
        Player(){
            x=0;
            y=0;
        }
        ~Player(){};
        void Interact(Cell* C){
            if (C->showSymbol() == 'a')
                cout<<"Interacted with animul1"<<endl;
            else if (C->showSymbol() == 'b')
                cout<<"Interacted with animul2"<<endl;
        }
};
*/
