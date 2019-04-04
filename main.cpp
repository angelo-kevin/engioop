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
//#include <unistd.h>

#define maxsize 256
using namespace std;

#include <cstdlib>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

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

void printMap(Player p, int time){
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
    int temp = p.getScore();
    while(temp / 10 > 0){
      moneySpaces++;
      temp /= 10;
    }

    for(int i = 0; i < colMax * 4; i++){
      if(i == 0){
        cout << "| Money: " << p.getScore();
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

    int waterSpaces = 0;
    temp = p.getPouch();
    while(temp / 10 > 0){
      waterSpaces++;
      temp /= 10;
    }

    for(int i = 0; i < colMax * 4; i++){
      if(i == 0){
        cout << "| Water: " << p.getPouch();
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

    for(int i = 0; i < colMax * 4; i++){
      if(i == 0){
        cout << "| Time: " << time;
      } else if(i >= 8){
        cout << " ";
      }
    }
    cout << "|" << endl;
}

void printLegend(){
  cout << "Keterangan:                  Controls:" << endl;
  cout << "B : Pig                      w : go up" << endl;
  cout << "C : Chicken                  a : go left" << endl;
  cout << "D : Duck                     s : go down" << endl;
  cout << "G : Goat                     d : go right" << endl;
  cout << "H : Horse" << endl;
  cout << "S : Cow                      talk     : talk to animal" << endl;
  cout << "M : Mixer                    interact : interact with things" << endl;
  cout << "T : Truck                    kill     : kill animal" << endl;
  cout << "W : Well                     grow     : grow grass" << endl;
  cout << "P : Player                   mix      : mix ingredients" << endl;
  cout << "x : Barn                     exit     : exit the game" << endl;
  cout << "o : Coop" << endl;
  cout << ". : Grassland" << endl;
  cout << "*, @, # : Grass" << endl;
}

int main(){
    int tick = 0;
    vector<FarmAnimal*> animalList;
    system(CLEAR);
    cout << " _____            _ _      ______                   " << endl;
    cout << "|  ___|          (_| )     |  ___|                  " << endl;
    cout << "| |__ _ __   __ _ _|/ ___  | |_ __ _ _ __ _ __ ___  " << endl;
    cout << "|  __| '_ \\ / _` | | / __| |  _/ _` | '__| '_ ` _ \\ " << endl;
    cout << "| |__| | | | (_| | | \\__ \\ | || (_| | |  | | | | | |" << endl;
    cout << "\\____/_| |_|\\__, |_| |___/ \\_| \\__,_|_|  |_| |_| |_|" << endl;
    cout << "             __/ |                                  " << endl;
    cout << "            |___/                                   " << endl;
    cout << "When in game, type exit to quit the game" << endl;
    cout << "Enter any key to start" << endl;
    string command = "";
    cout << "> ";
    cin >> command;
    cout << endl;

    loadMap();

    system(CLEAR);
    for(int i = 0; i < 3; i++){ //Spawn Chicken
      int x = 0;
      int y = 0;
      do{
        srand(time(0));
        x = (rand() % (gamemap.size()));
        y = (rand() % (gamemap[0].size()));
      } while(gamemap[x][y]->showSymbol() != 'o');

      FarmAnimal* a = new Chicken(x, y, false);
      animalList.push_back(a);
      gamemap[a->getX()][a->getY()]->animalOccupy(a);
    }
<<<<<<< HEAD

    for(int i = 0; i < 4; i++){ //Spawn Duck

    }

=======

    for(int i = 0; i < 4; i++){ //Spawn Duck

    }

>>>>>>> 2a4277eb4a258f14f0e6540e625f669c390bfd15
    for(int i = 0; i < 8; i++){ //Spawn Cow

    }

    for(int i = 0; i < 7; i++){ //Spawn Goat

    }

    for(int i = 0; i < 5; i++){ //Spawn Pig

    }

    for(int i = 0; i < 4; i++){ //Spawn Horse

    }

    FarmAnimal* a2 = new Chicken(1,5,true);
    gamemap[a2->getX()][a2->getY()]->animalOccupy(a2);

    //Construct Player:
    Player mainPlayer(5,5);
    gamemap[mainPlayer.getY()][mainPlayer.getX()]->playerOccupy();

    while(command != "exit"){
      //system(CLEAR);

      printMap(mainPlayer, tick);
      printLegend();
      cout << endl;
      cout << "Inventory: " << endl;
      cout << "" << endl;

      cout << "Command: ";
      cin >> command;
      transform(command.begin(), command.end(), command.begin(), ::tolower);

      if(command == "talk"){
        //cout << "insert talk direction: ";
        char c;
        cin >> c;
        mainPlayer.Talk(c);
      } else if(command == "interact"){
        //cout << "insert interact direction: ";
        char c;
        cin >> c;
        mainPlayer.Interact(c);
      } else if(command == "kill"){
        // cout << "kill" << endl;
        char c;
        cin >> c;
        mainPlayer.Kill(c);
      } else if(command == "grow"){
        // cout << "grow" << endl;
        char c;
        cin >> c;
        mainPlayer.Grow(c);
      } else if(command == "mix"){
        cout << "mix" << endl;
        char c;
        cin >> c;
        mainPlayer.Grow(c);
      } else if(command == "w" || command == "a" || command == "s" || command == "d"){
        gamemap[mainPlayer.getY()][mainPlayer.getX()]->makeUnoccupied();
        mainPlayer.setPosition(command[0]);
        gamemap[mainPlayer.getY()][mainPlayer.getX()]->playerOccupy();
      } else if(command == "exit"){
      } else{
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
    tick++;
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
