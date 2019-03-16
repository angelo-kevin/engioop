#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

#define maxsize 256
using namespace std;



//CLASSES:
class Cells{
    public:
        virtual ~Cells(){};
        virtual char showSymbol()=0;
};

//GLOBAL VARIABLES:
vector<vector<Cells*>> gamemap;

class Barn : public Cells{
    public:
        char showSymbol(){
            return 'x';
        }
};

class Land : public Cells{
    public:
        char showSymbol(){
            return '.';
        }
};

class Coop : public Cells{
    public:
        char showSymbol(){
            return 'o';
        }
};

class animul1: public Cells{
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

class animul2: public Cells{
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

        void Interact(Cells* C){
            if (C->showSymbol() == 'a')
                cout<<"Interacted with animul1"<<endl;
            else if (C->showSymbol() == 'b')
                cout<<"Interacted with animul2"<<endl;
        }

};

//FUNCTIONS:

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

void printMap(){
    vector< vector<Cells*> >::iterator row;
    vector<Cells*>::iterator col;
    for (row = gamemap.begin(); row != gamemap.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            cout<<(*col)->showSymbol();
        }
        cout<<endl;
    }
}


int main(){
    /*animul1* a = new animul1();
    gamemap.push_back(a);
    gamemap.push_back(new animul1());
    gamemap.push_back(new animul2());
    cout<<((gamemap.at(0))->showSymbol())<<endl;
    */

    //CREATE MAP:
    loadMap();
    printMap();
    Player p;
    p.Interact(gamemap[0][0]);
}