#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<ctype.h>
#include<map>
#include "Player.h"
#include "Animals/FarmAnimal.h"
#include "Facilities/Facility.h"
#include "Product/SideProduct/BaconOmelette.h"
#include "Product/SideProduct/HorseRolade.h"
#include "Product/SideProduct/MixedCheese.h"

#define MAX_WATER 100
using namespace std;

vector<char> eggProducingAnimal{'C','D'};
vector<char> milkProducingAnimal{'S','G'};
vector<char> arrayFacility{'W','T','M'};
map<string, vector<string>> recipe = {{"BaconOmelette", {"PigMeat","ChickenEgg"}},
                                    {"HorseRolade", {"HorseMeat", "DuckEgg"}},
                                    {"MixedCheese", {"CowMilk", "GoatMilk"}}};

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
    pouch = 20;
}

Player::Player(int x, int y){
    row=y;
    col=x;
    score=0;
    pouch=100;
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

void Player::printBackpack(){
    for (int i=0;i<backpack.getLength();i++){
        cout<<backpack.getData(i).getProductName()<<" ";
    }
    cout<<endl;
}

void Player::Talk(char dir){
    int x=0, y=0;
    Cell* cell = getPosition(dir,&x,&y);
    if (x<0 || x>=gamemap[0].size() || y<0 || y>=gamemap.size()) return;

    if (cell->getOverrideSymbol() != '\0'){ //animal
        cout<<cell->getAnimalPtr()->sound()<<endl;
    }else{
        cout<<"There's no animal.."<<endl;
    }
}

void Player::Interact(char dir){
    int x=0, y=0;
    Cell* cell = getPosition(dir,&x,&y);
    if (x<0 || x>=gamemap[0].size() || y<0 || y>=gamemap.size()) return;

    vector<char>::iterator itr1=find(arrayFacility.begin(),arrayFacility.end(),cell->showSymbol());

    if (cell->getOverrideSymbol()!='\0'){
        vector<char>::iterator itr2=find(milkProducingAnimal.begin(),milkProducingAnimal.end(),cell->getOverrideSymbol());
        vector<char>::iterator itr3=find(eggProducingAnimal.begin(),eggProducingAnimal.end(),cell->getOverrideSymbol());

        if (isupper(cell->getOverrideSymbol())){
            if (itr2!=milkProducingAnimal.end()){
                backpack.add(cell->getAnimalPtr()->produceMilk());
            }
            if (itr3!=eggProducingAnimal.end()){
                backpack.add(cell->getAnimalPtr()->produceEgg());

            }
            if (itr2!=milkProducingAnimal.end() || itr3!=eggProducingAnimal.end()){
                cell->getAnimalPtr()->revLapar();
                cell->animalOccupy(cell->getAnimalPtr());
                cout<<"Product is produced"<<endl;
            }

        }else{
            cout<<"Animal's hungry"<<endl;
        }

    }else if (itr1!=arrayFacility.end()){
        char c = cell->showSymbol();
        if (c=='W' || c=='w'){ //Well
            if (cell->showSymbol()=='m'){
                cout << "Well is unavailable"<<endl;
                return;
            }
            pouch = MAX_WATER;
            cout<<"Water's filled"<<endl;
            cell->getFacilityPtr()->invalidateFacility();
        }else if (c=='T'){//Truck
            int money=0;
            Product* arrProduct = new Product[backpack.getLength()];
            cell->getFacilityPtr()->invalidateFacility();
            for (int i=0; i<backpack.getLength();i++){
                money += backpack.getData(i).getHarga();
                Product P(0,backpack.getData(i).getProductName());
                arrProduct[i] = P;
                //backpack.removeByIdx(i);
            }

            backpack.remove(arrProduct,backpack.getLength());
            backpack.resetIndexing();
            cout<<"Money earned : "<<money<<endl;
            setScore(getScore()+money);
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
    int x=0, y=0;
    Cell* cell = getPosition(dir,&x,&y);
    if (x<0 || x>=gamemap[0].size() || y<0 || y>=gamemap.size()) return;

    if (cell->getOverrideSymbol() != '\0'){
        backpack.add(cell->getAnimalPtr()->produceMeat());
        cout<<cell->getAnimalPtr()->sound()<<endl;
        cell->makeUnoccupied();
        cout<<"Animal's killed"<<endl;

        vector<FarmAnimal*>::const_iterator itr = find(animalList.begin(), animalList.end(),cell->getAnimalPtr());
        if (itr!=animalList.end()) animalList.erase(itr);
    } else{
        cout<<"There's no animal.."<<endl;
    }
}

void Player::Grow(){
    if (pouch>0){
        gamemap[row][col]->growGrass();
        cout<<"Grass grown"<<endl;
        pouch--;
    }else{
        cout<<"Refill the pouch first"<<endl;
    }
}

void Player::Mix(char dir, string menu){ //jenis int
    int x=0, y=0;
    Cell* cell = getPosition(dir,&x,&y);
    if (x<0 || x>=gamemap[0].size() || y<0 || y>=gamemap.size()) return;
 
    if (cell->showSymbol()=='m'){
        cout << "Mixer is unavailable"<<endl;
        return;
    }
    if (cell->showSymbol()=='M'){
        map<string, vector<string>>::iterator itr;
        itr = recipe.find(menu);

        if (itr!=recipe.end()){
            //Invalidate mixer:
            cell->getFacilityPtr()->invalidateFacility();
            vector<string> ingredients = itr->second;
            int size = ingredients.size();
            Product* arrProduct = new Product[size];
            for (int i=0; i<size;i++){
                Product P(0,ingredients[i]);
                arrProduct[i] = P;
                //cout<<"Hello : "<<size<<" "<<ingredients[i]<<endl;
            }
                //cout<<"out from loop"<<endl;

            if (backpack.foundAll1(arrProduct,size)){
                backpack.remove(arrProduct,size);

                Product* newProduct;
                if (menu=="BaconOmelette"){
                    newProduct = new BaconOmelette();
                } else if (menu == "HorseRolade"){
                    newProduct = new HorseRolade();
                }else if (menu =="MixedCheese"){
                    newProduct = new MixedCheese();
                }else{
                    newProduct = new Product();
                }
                backpack.add(*newProduct);
                cout<<"Product's added"<<endl;
            }else{
                cout<<"Ingredients's not complete"<<endl;
            }
        }else{
            cout<<"Menu's not available.."<<endl;
        }
    }else{
        cout<<"Mixer's not here"<<endl;
    }
}

/*
int *x; //address x &x
int x; //address &x
x~&x
passing x;*/

//Ask for position:
Cell* Player::getPosition(char direction, int* x, int* y){
    direction = tolower(direction);
    int maxRow = gamemap.size();
    int maxCol = gamemap[0].size();

    if (direction == 'w'){
        *x=col;
        *y=row-1;
    }
    else if (direction == 'd'){
        *x=col+1;
        *y=row;
    }
    else if (direction == 's'){
        *x=col;
        *y=row+1;
    }
    else if (direction == 'a'){
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
}
