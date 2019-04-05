#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <ctype.h>
#include <sstream>
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

//facility-types:
#include "Facilities/FacilityTypes/Mixer.h"
#include "Facilities/FacilityTypes/Well.h"
#include "Facilities/FacilityTypes/Truck.h"

//Animal-types:
#include "Animals/FarmAnimal.h"
#include "Animals/Pig.h"
#include "Animals/Chicken.h"
#include "Animals/Goat.h"
#include "Animals/Horse.h"
#include "Animals/Duck.h"
#include "Animals/Cow.h"

//Player:
#include "Player.h"

//Product:
#include "Product/Product.h"

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
        Truck* temp = new Truck();
        v.push_back(temp);
        facilityList.push_back(temp);
        v[v.size()-1]->setFacilityPtr(temp);
    }
    else if (c == 'W'){
        Well* temp = new Well();
        v.push_back(temp);
        facilityList.push_back(temp);
        v[v.size()-1]->setFacilityPtr(temp);
    }
    else if (c == 'M'){
        Mixer* temp = new Mixer();
        v.push_back(temp);
        facilityList.push_back(temp);
        v[v.size()-1]->setFacilityPtr(temp);
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

    else cout << "File read error";
    mapfile.close();
}

void printMap(int money, int aqua, int tick){
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
    for (row = gamemap.begin(); row != gamemap.end(); ++row) {
        cout << "| ";
        for (col = row->begin(); col != row->end(); ++col) {
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
    
    //jumlah digit yang ada di money
    int moneySpaces = to_string(money).length();

    for(int i = 0; i < colMax * 4; i++){
      if(i == 0){
        cout << "| Money: " << money;
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
    
    //jumlah digit yang ada di pouch
    int waterSpaces = to_string(aqua).length();

    for(int i = 0; i < colMax * 4; i++){
      if(i == 0){
        cout << "| Water: " << aqua;
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
    
    //jumlah digit yang ada di timer
    int timerSpaces = to_string(tick).length();
    for(int i = 0; i < colMax * 4; i++){
      if(i == 0){
        cout << "| Timer: " << tick;
      } else if(i >= 9 + timerSpaces){
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

void moveAllAnimals(){
  for(int i = 0; i<animalList.size(); i++){
    gamemap[animalList[i]->getX()][animalList[i]->getY()]->makeUnoccupied();
    animalList[i]->move();
    gamemap[animalList[i]->getX()][animalList[i]->getY()]->animalOccupy(animalList[i]);
  }
}

void updateAllFacilities(){
  for(int i = 0; i<facilityList.size(); i++){
    facilityList[i]->facilityUpdate();
  }
}

void printLegend(){
  cout << "Keterangan:                  Controls:" << endl;
  cout << "B : Pig                      w : go up" << endl;
  cout << "C : Chicken                  a : go left" << endl;
  cout << "D : Duck                     s : go down" << endl;
  cout << "G : Goat                     d : go right" << endl;
  cout << "H : Horse" << endl;
  cout << "S : Cow                      talk (dir)        : talk to animal" << endl;
  cout << "M : Mixer                    interact (dir)    : interact with things" << endl;
  cout << "T : Truck                    kill (dir)        : kill animal" << endl;
  cout << "W : Mixer                    grow (dir)        : grow grass" << endl;
  cout << "P : Player                   mix (dir, recipe) : mix ingredients" << endl;
  cout << "x : Barn                     exit              : exit the game" << endl;
  cout << "o : Coop" << endl;
  cout << ". : Grassland" << endl;
  cout << "*, @, # : Grass" << endl;
}

int main(){
    int tick = 0;
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
    cout << "Press enter to start";
    string command = "";
    cin.ignore();

    loadMap();

    //Construct Player:
    Player mainPlayer(5,5);
    gamemap[mainPlayer.getY()][mainPlayer.getX()]->playerOccupy();

    system(CLEAR);

    //Bagian Spawn Animal secara random
    //Spawn 3 Chickens
    for(int i = 0; i < 3; i++){
      int x = 0;
      int y = 0;
      srand(time(0));
      //Loop until correct position is found
      do{
        x = (rand() % (gamemap.size()));
        y = (rand() % (gamemap[0].size()));
      } while(gamemap[x][y]->showSymbol() != 'o' || (gamemap[x][y]->getOverrideSymbol() != '\0'));
      FarmAnimal* a = new Chicken(x, y, false);
      //add animal into list of animal
      animalList.push_back(a);
      //update gamemap
      gamemap[x][y]->animalOccupy(a);
    }

    //Spawn 4 Ducks
    for(int i = 0; i < 4; i++){
      int x = 0;
      int y = 0;
      srand(time(0));
      //Loop until correct position is found
      do{
        x = (rand() % (gamemap.size()));
        y = (rand() % (gamemap[0].size()));
      } while(gamemap[x][y]->showSymbol() != 'o' || (gamemap[x][y]->getOverrideSymbol() != '\0'));
      FarmAnimal* a = new Duck(x, y, false);
      //add animal into list of animal
      animalList.push_back(a);
      //update gamemap
      gamemap[x][y]->animalOccupy(a);
    }

    //Spawn 8 Cows
    for(int i = 0; i < 8; i++){
      int x = 0;
      int y = 0;
      srand(time(0));
      //Loop until correct position is found
      do{
        x = (rand() % (gamemap.size()));
        y = (rand() % (gamemap[0].size()));
      } while(gamemap[x][y]->showSymbol() != '.' || (gamemap[x][y]->getOverrideSymbol() != '\0'));
      FarmAnimal* a = new Cow(x, y, false);
      //add animal into list of animal
      animalList.push_back(a);
      //update gamemap
      gamemap[x][y]->animalOccupy(a);
    }

    //Spawn 7 Goats
    for(int i = 0; i < 7; i++){
      int x = 0;
      int y = 0;
      srand(time(0));
      //Loop until correct position is found
      do{
        x = (rand() % (gamemap.size()));
        y = (rand() % (gamemap[0].size()));
      } while(gamemap[x][y]->showSymbol() != '.' || (gamemap[x][y]->getOverrideSymbol() != '\0'));
      FarmAnimal* a = new Goat(x, y, false);
      //add animal into list of animal
      animalList.push_back(a);
      //update gamemap
      gamemap[x][y]->animalOccupy(a);
    }

    //Spawn 5 Pigs
    for(int i = 0; i < 5; i++){
      int x = 0;
      int y = 0;
      srand(time(0));
      //Loop until correct position is found
      do{
        x = (rand() % (gamemap.size()));
        y = (rand() % (gamemap[0].size()));
      } while(gamemap[x][y]->showSymbol() != 'x' || (gamemap[x][y]->getOverrideSymbol() != '\0'));
      FarmAnimal* a = new Pig(x, y, false);
      //add animal into list of animal
      animalList.push_back(a);
      //update gamemap
      gamemap[x][y]->animalOccupy(a);
    }

    //Spawn 4 Horses
    for(int i = 0; i < 4; i++){
      int x = 0;
      int y = 0;
      srand(time(0));
      //Loop until correct position is found
      do{
        x = (rand() % (gamemap.size()));
        y = (rand() % (gamemap[0].size()));
      } while(gamemap[x][y]->showSymbol() != 'x' || (gamemap[x][y]->getOverrideSymbol() != '\0'));
      FarmAnimal* a = new Horse(x, y, false);
      //add animal into list of animal
      animalList.push_back(a);
      //update gamemap
      gamemap[x][y]->animalOccupy(a);
    }

    ostringstream *local=NULL;
    //Main loop. will loop until "exit" is inputted or all animals died
    while(command != "exit" && animalList.size() > 0){
      // print 'local' content
      system(CLEAR); 

      //Move all animal every 2 ticks
      if(tick != 0 && tick % 2 == 0){
        moveAllAnimals();
      }
      //Erase dead animal and eat if hungry
      for(int i = 0; i < animalList.size(); i++){
        gamemap[animalList[i]->getX()][animalList[i]->getY()]->makeUnoccupied();
        animalList[i]-> eat();
        gamemap[animalList[i]->getX()][animalList[i]->getY()]->animalOccupy(animalList[i]);
        if(animalList[i]->getThreshold() <= -5){
          gamemap[animalList[i]->getX()][animalList[i]->getY()]->makeUnoccupied();
          animalList.erase(animalList.begin() + i);
        }
      }
      
      //Update all facilities:
      updateAllFacilities();

      //print the map
      printMap(mainPlayer.getScore(), mainPlayer.getPouch(), tick);
      //print the legend
      printLegend();

      //if all animal is dead, break from loop and game over
      if(animalList.size() == 0){
        break;
      }

      cout << endl;
      cout << "Inventory: ";
      mainPlayer.printBackpack();
      cout << "" << endl;

      cout << "OUTPUT: " << endl;
      if (local != NULL){
        cout << local->str() <<endl;
      }
      local = new ostringstream();

      cout << "Command: ";
      cin >> command;
      //lowercase the command input
      transform(command.begin(), command.end(), command.begin(), ::tolower);

      cout << endl;

      auto cout_buff = cout.rdbuf(); // save pointer to cout buffer

      cout.rdbuf(local->rdbuf()); // substitute internal cout buffer with
      // buffer of 'local' object

      // now cout work with 'local' buffer
      // you don't see this message
      // cout << "some message";
      if(command == "talk"){ //talk action
        char c;
        cin >> c; //direction to talk to
        mainPlayer.Talk(c);
      } else if(command == "interact"){ //interact action
        char c;
        cin >> c; //direction to interact to
        mainPlayer.Interact(c);
      } else if(command == "kill"){ //kill action
        char c;
        cin >> c; //direction to kill animal
        mainPlayer.Kill(c);
      } else if(command == "grow"){ //grow action
        mainPlayer.Grow();
      } else if(command == "mix"){ //mix action
        char c;
        cin >> c;
        string menu;
        cin >> menu;
        mainPlayer.Mix(c,menu);
      } else if(command == "w" || command == "a" || command == "s" || command == "d"){ //move action
        gamemap[mainPlayer.getY()][mainPlayer.getX()]->makeUnoccupied();
        mainPlayer.setPosition(command[0]);
        gamemap[mainPlayer.getY()][mainPlayer.getX()]->playerOccupy();
      } else if(command == "cheats"){
        int x,y;
        cin>>y;
        cin>>x;
        gamemap[mainPlayer.getY()][mainPlayer.getX()]->makeUnoccupied();
        cout << "cheats "<<endl;
        mainPlayer.setX(x);
        mainPlayer.setY(y);
        gamemap[mainPlayer.getY()][mainPlayer.getX()]->playerOccupy();
      } else if(command == "exit"){
      } else{
        tick--;
        cout << "Invalid command" << endl;
      }

    tick++;
    //Decrement hunger threshold for all animal
    for(int i = 0; i < animalList.size(); i++){
      animalList[i]->minThreshold();
    }
    // go back to old buffer
    cout.rdbuf(cout_buff);

    // you will see this message
    // cout << "back to default buffer\n";

  }

  cout << "                 GAME OVER" << endl;
  cout << "---------------------------------------------" << endl;
  cout << "Final score: " << mainPlayer.getScore() << endl;
}
