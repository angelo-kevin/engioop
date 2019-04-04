#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<ctype.h>
#include<map>
#include "Player.h"
#include "Animals/FarmAnimal.h"

#define MAX_WATER 100
using namespace std;

vector<char> eggProducingAnimal{'C'};
vector<char> milkProducingAnimal{'S'};
vector<char> arrayFacility{'W','T','M'};
map<string, vector<string>> recipe = {{"mayonaise", {"egg","milk"}},
                                    {"cheese", {"milk"}}};

map<char,vector<FarmAnimal*>> liveAnimals; //adding same key will be overide orginal value


/*
struct comparePos
{
    int key1, key2;
	comparePos(int x, int y): key1(x),key2(y) { }
	bool operator()(FarmAnimal& obj)
	{
		return (obj.getX() == key1 && obj.getY() == key2);
	}
};
*/

Player::Player(){
    row = 0;
    col = 0;
    score = 0;
    pouch = 0;
}

Player::Player(int x, int y){
    row=y;
    col=x;
    score=0;
}

int Player::getX(){
    return col;
}

int Player::getY(){
    return row;
}

int Player::getPouch(){
    return pouch;
}
int Player::getScore(){
    return score;
}
LinkedList<Product> Player::getBackpack(){
    return backpack;
}

void Player::setPouch(int temp){
    pouch=temp;
}
void Player::setX(int x){
    col=x;
}
void Player::setY(int y){
    row=y;
}
void Player::setScore(int s){
    score = s;
}

void Player::Talk(char dir){
    int *x, *y;
    Cell* cell = getPosition(dir,x,y);
    if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;

    if (cell->getOverrideSymbol() != '\0'){ //animal
        cout<<cell->getAnimalPtr()->sound()<<endl;
    }else{
        cout<<"There's no animal.."<<endl;
    }
}

void Player::Interact(char dir){
    int *x, *y;
    Cell* cell = getPosition(dir,x,y);
    if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;

    vector<char>::iterator itr1=find(arrayFacility.begin(),arrayFacility.end(),cell->showSymbol());

    if (cell->getOverrideSymbol()!='\0'){
        vector<char>::iterator itr2=find(milkProducingAnimal.begin(),milkProducingAnimal.end(),cell->showSymbol());
        vector<char>::iterator itr3=find(eggProducingAnimal.begin(),eggProducingAnimal.end(),cell->showSymbol());

        if (isupper(cell->getOverrideSymbol())){
            if (itr2!=milkProducingAnimal.end()){
                backpack.add(cell->getAnimalPtr()->produceMilk());
            }
            if (itr3!=eggProducingAnimal.end()){
                backpack.add(cell->getAnimalPtr()->produceEgg());
            }
            cell->getAnimalPtr()->revLapar();
            cell->getAnimalPtr()->revSimbol();
        }else{
            cout<<"Animal's hungry"<<endl;
        }

    }else if (itr1!=arrayFacility.end()){
        char c = cell->showSymbol();
        if (c=='W'){ //Well
            pouch = MAX_WATER;
        }else if (c=='T'){//Truck
            int money=0;
            for (int i=0; i<backpack.getLength();i++){
                money += backpack.getData(i).getHarga();
                backpack.removeByIdx(i);
            }
            backpack.resetIndexing();
            cout<<"Money earned : "<<money<<endl;
            score+=money;
        }else if (c=='t'){
            cout<<"Truck's not available"<<endl;
        }else{
            cout<<"Cannot interact with the facility."<<endl;
        }
    }else{
        cout<<"Interact Failed."<<endl;
    }
}


void Player::Kill(char dir){
    int *x, *y;
    Cell* cell = getPosition(dir,x,y);
    if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;

    if (cell->getOverrideSymbol() != '\0'){
        backpack.add(cell->getAnimalPtr()->produceMeat());
        cout<<cell->getAnimalPtr()->sound()<<endl;
        cell->makeUnoccupied();
        //delete from "livinganimal" list
    }else{
        cout<<"There's no animal.."<<endl;
    }
}

void Player::Grow(char dir){
    int *x, *y;
    Cell* cell = getPosition(dir,x,y);
    if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;
    cell->growGrass();
}

void Player::Mix(char dir, string menu){ //jenis int
    int *x, *y;
    Cell* cell = getPosition(dir,x,y);
    if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;

    if (cell->showSymbol()=='M'){
        map<string, vector<string>>::iterator itr;
        itr = recipe.find(menu);
        if (itr!=recipe.end()){
            vector<string> ingredients = itr->second;
            vector<string>::iterator itr2;
            int size = ingredients.size();
            Product* arrProduct = new Product[size];
            for (int i=0; i<size;i++){
                Product P(0,ingredients[i]);
                arrProduct[i] = P;
            }
            backpack.remove(arrProduct,size);
        }else{
            cout<<"Menu's not available.."<<endl;
        }
    }
}


//Ask for position:
Cell* Player::getPosition(char direction, int* x, int* y){
    direction = tolower(direction);
    int maxRow = gamemap.size();
    int maxCol = gamemap[0].size();

    if (direction == 'n'){
        *x=col;
        *y=row-1;
    }
    else if (direction == 'e'){
        *x=col+1;
        *y=row;
    }
    else if (direction == 's'){
        *x=col;
        *y=row+1;
    }
    else if (direction == 'w'){
        *x=col-1;
        *y=row;
    }

    if (0<=*y && *y<maxRow && 0<=*x && *x<maxCol){
        return gamemap[*y][*x];
    }else{
        cout<<"Cell is out of range"<<endl;
        return new Cell();
    }
}

bool Player::canPassed(int tcol, int trow){
    return (gamemap[trow][tcol]->getOverrideSymbol()=='\0' && gamemap[trow][tcol]->showSymbol()!='M' && gamemap[trow][tcol]->showSymbol()!='T' && gamemap[trow][tcol]->showSymbol()!='W');
}
//Player change position:
void Player::setPosition(char direction){
    direction = tolower(direction);
    if (direction == 'w' && 0<=row-1 && canPassed(col,row-1)){
        row--;
    }
    else if (direction == 'd' && col+1<gamemap[0].size() && canPassed(col+1,row)){
        col++;
    }
    else if (direction == 's' && row+1<gamemap.size() && canPassed(col,row+1)){
        row++;
    }
    else if (direction == 'a' && 0<=col-1 && canPassed(col-1, row)){
        col--;
    }
    else{
        cout << "JESNAT SALAH" << endl;
    }
    cout<<"Player direction: " << direction <<", curpos: " << row << " " << col << endl;
}
