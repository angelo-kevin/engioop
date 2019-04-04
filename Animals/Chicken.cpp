#include "Chicken.h"
#include <iostream>
#include "../common.h"

using namespace std;

Chicken::Chicken(int x, int y, bool l): FarmAnimal(x,y,l), EggProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 'c';
    else simbol = 'C';
    threshold = 8;
}

void Chicken::move(){
    int x;
    int ctr=0;
    int row, col;
    do{
        ctr = 0;
        srand(time(0));
        x = (rand()%4)+1;
        if (x==1){
            row = getX();
            setX(row+1);
            if (getX()>=gamemap.size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                //cout << gamemap[getX()][getY()]->getOverrideSymbol();
                setX(row);
                ctr++;
                //cout << "1" << endl;
            }
            
        }
        else if (x==2){
            col = getY();
            setY(col+1);
            if (getY()>=gamemap[0].size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                //cout << gamemap[getX()][getY()]->getOverrideSymbol();
                setY(col);
                ctr++;
                //cout << "2" << endl;
            }
            
        }
        else if (x==3){
            row = getX();
            setX(row-1);
            if (getX()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                //cout << gamemap[getX()][getY()]->getOverrideSymbol();
                setX(row);
                ctr++;
                //cout << "3" << endl;
            }
            
        }
        else if (x==4){
            col = getY();
            setY(col-1);
            if (getY()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                //cout << (gamemap[getX()][getY()]->getOverrideSymbol()!='\0') << "LALALAhgvyu" << endl;
                setY(col);
                ctr++;
                //cout << "jhbubu4" << endl;
            }
            
        }
        //cout << "POSISI NOW:" << getX() <<", " << getY()<< endl;
        //cout << ctr << endl;
    } while (ctr!=0);
} //implementasi fungsi pure virtual dari parent

string Chicken::sound(){
    return "petok";
} //suara 'petok'

FarmProduct Chicken::produceEgg(){
    return ChickenEgg();
}

FarmProduct Chicken::produceMeat(){
    return ChickenMeat();
}