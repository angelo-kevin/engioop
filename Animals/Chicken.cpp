#include "Chicken.h"

Chicken::Chicken(int x, int y, bool l): FarmAnimal(x,y,l), EggProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 'c';
    else simbol = 'C';
    threshold = 8;
}

void Chicken::move(){
    int x;
    int ctr;
    int row, col;
    if (threshold<=0) lapar = true;
    if (lapar && gamemap[getX()][getY()]->showSymbol()=='*'){
        gamemap[getX()][getY()]->makeUnoccupied();
        lapar = false;
        threshold = 8;
    }
    do{
        ctr = 0;
        srand(time(0));
        x = (rand()%4)+1;
        if (x==1){
            row = getX();
            setX(row+1);
            if (getX()>=gamemap.size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                setX(row);
                ctr++;
            }
        }
        else if (x==2){
            col = getY();
            setY(col+1);
            if (getY()>=gamemap[0].size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                setY(col);
                ctr++;
            }
        }
        else if (x==3){
            row = getX();
            setX(row-1);
            if (getX()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                setX(row);
                ctr++;
            }
        }
        else if (x==4){
            col = getY();
            setY(col-1);
            if (getY()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                setY(col);
                ctr++;
            }
        }
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