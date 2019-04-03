#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<ctype.h>
#include<map>
#include "Player.h"
#define MAX_WATER 100
using namespace std;

vector<char> arrayProducingAnimal{'a','A'}; //except MeatProducing
vector<char> arrayKillAnimal{'c','C'};
vector<char> arrayAnimal{'a','A','c','C'};
vector<char> arrayFacility{'W','T'}; //except mixer;
vector<char> arrayMixer{'M'};
vector<char> arrayLand{'L'};
map<string, vector<string>> recipe = {{"mayonaise", {"egg","milk"}}, 
                                    {"cheese", {"milk"}}};

map<char,vector<FarmAnimal>> liveAnimals; //adding same key will be overide orginal value

template<class T>
struct comparePos
{
    int key1, key2;
	comparePos(int x, int y): key1(x),key2(y) { }

	bool operator()(T&  const obj)
	{
		return (obj.getX() == key1 && obj.getY() == key2);
	}
};

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
            vector<char>::iterator itr=find(arrayAnimal.begin(),arrayAnimal.end(),cell->showSymbol());
            if (itr!=arrayAnimal.end()){
                char c = cell->showSymbol();
                vector<FarmAnimal>::iterator itr = find_if(liveAnimals[c].begin(),liveAnimals[c].end(),comparePos<FarmAnimal>(*x,*y));
                cout<<itr->sound()<<endl;
            }
        }

        void Interact(char dir){
            int *x, *y;
            Cell* cell = getPosition(dir,x,y);
            vector<char>::iterator itr=find(arrayProducingAnimal.begin(),arrayProducingAnimal.end(),cell->showSymbol());
            vector<char>::iterator itr2=find(arrayFacility.begin(),arrayFacility.end(),cell->showSymbol());
            char c = cell->showSymbol();

            if (itr!=arrayAnimal.end()){ //get the produced
                if (isupper(c)){
                    vector<FarmAnimal>::iterator itr = find_if(liveAnimals[c].begin(),liveAnimals[c].end(),comparePos<FarmAnimal>(*x,*y));
                    cout<<"Product added"<<endl;
                    backpack.add(itr->produce());
                    cell->setSymbol(tolower(c));
                }else{
                    cout<<"The animal seems to be hungry."<<endl;
                }
            }else if (itr2!=arrayFacility.end()){
                if (c=='W'){ //Well
                    pouch = MAX_WATER;
                }else if (c=='T'){//Truck
                    if (){
                        int money=0;
                        for (int i=0; i<backpack.getLength();i++){
                            money += backpack.getData(i).getHarga();
                            backpack.removeByIdx(i);
                        }
                        backpack.resetIndexing();
                        cout<<"Money earned : "<<money<<endl;
                        score+=money;
                    }else{
                        cout<<"Truck's not available"<<endl;
                    }
                }
            }

            /*

            if (C->showSymbol() == 'a')
                cout<<"Interacted with animul1"<<endl;
            else if (C->showSymbol() == 'b')
                cout<<"Interacted with animul2"<<endl;
            */
        }
        

        void Kill(Cell* C){
            vector<char>::iterator itr=find(arrayKillAnimal.begin(),arrayKillAnimal.end(),C->showSymbol());
            if (itr!=arrayKillAnimal.end()){
                //itr->~dest

                //mappp
            }


            

        }

        void Grow(Cell* C){
            vector<char>::iterator itr=find(arrayLand.begin(),arrayLand.end(),C->showSymbol());
            if (itr!=arrayLand.end()){
                //mapp
            }

        }

        void Mix(string str){ //jenis int 
            vector<string>::iterator itr=recipe[str].begin();
            vector<Product>::iterator itr;
            while (itr!=recipe[str].end()){
                vector<Product>::iterator itr2=find(backpack.begin(),backpack.end(),*itr); 
                if(itr2!=backpack.end()){
                    
                }else{

                }
                
                itr++;

            }

        }
        void classIdentifier(char c, vector<Cell*> &v){
        //ALSO PUTS IT INTO VECTHOR
        if (c == '.'){
            v.push_back(new Land());
        }
        else if (c == 'o'){
            v.push_back(new Coop());
        }
        else if (c == 'x'){
            v.push_back(new Barn());
        }
        else if (c == '#'){
            v.push_back(new Grassland());
        }
        else if (c == 'M'){
            v.push_back(new Mixer());
        }
        else if (c == 'W'){
            v.push_back(new Well());
        }
        else if (c == 'T'){
            v.push_back(new Truck());
        }
        else if (c == 'a'){
            v.push_back(new animul1());
        }
        else if (c == 'b'){
            v.push_back(new animul2());
        }
    }

    //Ask for position:

    Cell* getPosition(char direction, int* x, int* y){
        direction = tolower(direction);
        if (direction == 'n'){
            *x=col;
            *y=row-1;
            return gamemap[(this->row)-1][this->col];
        }
        else if (direction == 'e'){
            *x=col+1;
            *y=row;
            return gamemap[this->row][(this->col)+1];
        }
        else if (direction == 's'){
            *x=col;
            *y=row+1;
            return gamemap[(this->row)+1][this->col];
        }
        else if (direction == 'w'){
            *x=col-1;
            *y=row;
            return gamemap[this->row][(this->col)-1];
        }
    }

    //Player change position:
    void setPosition(char direction){
        direction = tolower(direction);
        if (direction == 'n'){
            (this->row)--;
        }
        else if (direction == 'e'){
            (this->col)++;
        }
        else if (direction == 's'){
            (this->row)++;
        }
        else if (direction == 'w'){
            (this->col)--;
        }
    }
}
