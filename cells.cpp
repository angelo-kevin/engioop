#include <iostream>
#include <vector>
#include <cstring>
#define maxsize 256
using namespace std;

class cells{
    public:
        virtual ~cells(){};
        virtual char showSymbol()=0;
};

class animul1: public cells{
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

class animul2: public cells{
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

        void Interact(cells* C){
            if (C->showSymbol() == 'a')
                cout<<"Interacted with animul1"<<endl;
            else if (C->showSymbol() == 'b')
                cout<<"Interacted with animul2"<<endl;
        }

};

int main(){
    vector<cells*> gamemap;
    animul1* a = new animul1();
    gamemap.push_back(a);
    gamemap.push_back(new animul1());
    gamemap.push_back(new animul2());
    cout<<((gamemap.at(0))->showSymbol())<<endl;
    Player p;
    p.Interact(gamemap.at(0));
}