#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<ctype.h>
#include<map>
#include "Player.h"
#define MAX_WATER 100
using namespace std;

vector<char> meatProducingAnimal{'B'};
vector<char> eggProducingAnimal{'C'};
vector<char> milkProducingAnimal{'S'};
vector<char> arrayAnimal{'a','A','c','C'};
vector<char> arrayFacility{'W','T'}; //except mixer;
vector<char> arrayMixer{'M'};
vector<char> arrayLand{'L'};
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
class Player{
    private:
        int row;
        int col;
        LinkedList<Product> backpack;
        int score;
        //int nell; //backpack
        int pouch; // water
    public:
        Player(){
            row=0;
            col=0;
            score=0;
        }

        ~Player(){};

        
        void Talk(char dir){
            int *x, *y;
            Cell* cell = getPosition(dir,x,y);
            if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;

            if (cell->getOverrideSymbol() != '\0'){ //animal
                //vector<char>::iterator itr=find(arrayAnimal.begin(),arrayAnimal.end(),cell->showSymbol());
                // char c = cell->showSymbol();
                // vector<FarmAnimal>::iterator itr = find_if(liveAnimals[c].begin(),liveAnimals[c].end(),comparePos(*x,*y));
                // cout<<itr->sound()<<endl;
                cout<<cell->getAnimalPtr()->sound<<endl;
            }else{
                cout<<"There's no animal.."<<endl;
            }
        }

        void Interact(char dir){
            int *x, *y;
            Cell* cell = getPosition(dir,x,y);
            if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;

            vector<char>::iterator itr1=find(arrayFacility.begin(),arrayFacility.end(),cell->showSymbol());

            if (cell->getOverrideSymbol()!='\0'){
                vector<char>::iterator itr2=find(milkProducingAnimal.begin(),milkProducingAnimal.end(),cell->showSymbol());
                vector<char>::iterator itr3=find(eggProducingAnimal.begin(),eggProducingAnimal.end(),cell->showSymbol());

                if (isupper(cell->getOverrideSymbol())){
                    if (itr2!=milkProducingAnimal.end()){
                        backpack.add(cell->getAnimalPtr()->producemilk());
                    }
                    if (itr3!=eggProducingAnimal.end()){
                        backpack.add(cell->getAnimalPtr()->producemilk());
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
        

        void Kill(char dir){
            int *x, *y;
            Cell* cell = getPosition(dir,x,y);
            if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;

            if (cell->getOverrideSymbol() != '\0'){
                backpack.add(cell->getAnimalPtr()->producemeat());
                cout<<cell->getAnimalPtr()->sound<<endl;
                cell->makeUnoccupied();
                //delete from "livinganimal" list
            }else{
                cout<<"There's no animal.."<<endl;
            }
        }

        void Grow(char dir){
            int *x, *y;
            Cell* cell = getPosition(dir,x,y);
            if (x<0 || *x>=gamemap[0].size() || y<0 || *y>=gamemap.size()) return;
            cell->growGrass();
        }

        void Mix(char dir, string menu){ //jenis int
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

        Cell* getPosition(char direction, int* x, int* y){
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

        //Player change position:
        void setPosition(char direction){
            direction = tolower(direction);
            if (direction == 'n'){
                row--;
            }
            else if (direction == 'e'){
                col++;
            }
            else if (direction == 's'){
                row++;
            }
            else if (direction == 'w'){
                col--;
            }
            if (row<0) row=0;
            if (row>=gamemap.size()) row=gamemap.size()-1;
            if (col<0) col=0;
            if (col>=gamemap[0].size()) col=gamemap[0].size()-1;
        }
}
