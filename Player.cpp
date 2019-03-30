#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "Land.h"
#include "Cell.h"
using namespace std;

vector<char> arrayProducingAnimal{'a','A'}; //except MeatProducing
vector<char> arrayKillAnimal{'c','C'};
vector<char> arrayAnimal{'a','A','c','C'};
vector<char> arrayFacility{'W','T'}; //except mixer;
vector<char> arrayMixer{'M'};
vector<char> arrayLand{'L'};
map<string, vector<string>> recipe = {{"mayonaise", {"egg","milk"}}, 
                                    {"cheese", {"milk"}}};


class Product:A{
    private a;

};


class Side: public Product {


};



class Player{
    private:
        int row;
        int col;
        vector<Product> backpack;
        //int nell; //backpack
        int pouch; // water
    public:
        Player(){
            row=0;
            col=0;
        }

        ~Player(){};

        void Talk(Cells* C){
            vector<char>::iterator itr=find(arrayAnimal.begin(),arrayAnimal.end(),C->showSymbol());
            if (itr!=arrayAnimal.end()){
                //itr->sound();
            }
        }

        void Interact(Cells* C){
            vector<char>::iterator itr=find(arrayProducingAnimal.begin(),arrayProducingAnimal.end(),C->showSymbol());
            vector<char>::iterator itr2=find(arrayFacility.begin(),arrayFacility.end(),C->showSymbol());

            if (itr!=arrayAnimal.end()){
                //itr->produce();
                //backpack;
            }else if (itr2!=arrayFacility.end()){
                // truck
                // water

                //itr->prodduce();
            }

            /*

            if (C->showSymbol() == 'a')
                cout<<"Interacted with animul1"<<endl;
            else if (C->showSymbol() == 'b')
                cout<<"Interacted with animul2"<<endl;
            */
        }

        void Kill(Cells* C){
            vector<char>::iterator itr=find(arrayKillAnimal.begin(),arrayKillAnimal.end(),C->showSymbol());
            if (itr!=arrayKillAnimal.end()){
                //itr->~dest

                //mappp
            }


            

        }

        void Grow(Cells* C){
            vector<char>::iterator itr=find(arrayLand.begin(),arrayLand.end(),C->showSymbol());
            if (itr!=arrayLand.end()){
                //mapp
            }

        }

        void Mix(string str){ //jenis int 
            vector<string>::iterator itr=recipe[str].begin();
            vector<Product>::iterator itr;
            while (itr!=recipe[str].end()){
                vector<Product>::iterator[] itr2=find(backpack.begin(),backpack.end(),*itr); 
                if(itr2!=backpack.end()){
                    
                }else{

                }
                
                itr++;

            }

        }
        void classIdentifier(char c, vector<Cells*> &v){
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
            v.push_back(new Grass());
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
    void loadMap(){
        ifstream mapfile;
        string line;
        int idx;
        vector<Cells*> tempv;
        mapfile.open ("mapschema.txt");
        if (mapfile.is_open())
        {
            while ( getline (mapfile,line) )
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

    //Ask for position:

    Cells* getPosition(char direction){
        direction = tolower(direction);
        if (direction == 'n'){
            return gamemap[(this->row)-1][this->col];
        }
        else if (direction == 'e'){
            return gamemap[this->row][(this->col)+1];
        }
        else if (direction == 's'){
            return gamemap[(this->row)+1][this->col];
        }
        else if (direction == 'w'){
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
