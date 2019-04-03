#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "Player.h"
#include "Cell.h"

using namespace std;

vector<char> eggProducingAnimal{'C'};
vector<char> milkProducingAnimal{'S'};
vector<char> arrayFacility{'W','T','M'};
map<string, vector<string>> recipe = {{"mayonaise", {"egg","milk"}}, 
                                    {"cheese", {"milk"}}};


class Player{
    private:
        int row;
        int col;
        LinkedList<Product> backpack;
        //int nell; //backpack
        int pouch; // water
    public:
        Player(){
            row=0;
            col=0;
        }

        ~Player(){};

        void Talk(Cell* C){
            vector<char>::iterator itr = find(arrayAnimal.begin(),arrayAnimal.end(),C->showSymbol());
            if (itr!=arrayAnimal.end()){
                cout<<itr->sound()<<endl;
            }
        }

        void Interact(Cell* C){
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

            if (cell->getOverrideSymbol() != '\0'){
                backpack.add(cell->getAnimalPtr()->produceMeat());
                cout<<cell->getAnimalPtr()->sound<<endl;
                cell->makeUnoccupied();
                //delete from "livinganimal" list
            }else{
                cout<<"There's no animal.."<<endl;
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
    void loadMap(){
        ifstream mapfile;
        string line;
        int idx;
        vector<Cell*> tempv;
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

    Cell* getPosition(char direction){
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

        bool canPassed(int tcol, int trow){
            return (gamemap[trow][tcol]->getOverrideSymbol!='\0' && gamemap[trow][tcol]->showSymbol!='M' && gamemap[trow][tcol]->showSymbol!='T' && gamemap[trow][tcol]->showSymbol!='W');
        }
        //Player change position:
        void setPosition(char direction){
            direction = tolower(direction);
            if (direction == 'n' && 0<=row-1 && canPassed(col,row-1)){
                row--;  
            }
            else if (direction == 'e' && col+1<gamemap[0].size() && canPassed(col+1,row)){
                col++;
            }
            else if (direction == 's' && row+1<gamemap.size() && canPassed(col,row+1)){
                row++;
            }
            else if (direction == 'w' && 0<=col-1 && canPassed(col-1, row)){
                col--;
            }
        }
    }
}
