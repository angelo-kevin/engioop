#include "Cow.h"

Cow::Cow(int x, int y, bool l): FarmAnimal(x,y,l), MilkProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 's';
    else simbol = 'S';
    threshold = 10;
}

void Cow::move(){
    int x;
    int ctr;
    int row, col;
    if (threshold<=0) lapar = true;
    if (lapar && gamemap[getX()][getY()]->showSymbol()=='#'){
        gamemap[getX()][getY()]->makeUnoccupied();
        lapar = false;
        threshold = 10;
    }
    do{
        ctr = 0;
        srand(time(0));
        x = (rand()%4)+1;
        if (x==1){
            row = getX();
            setX(row+1);
            if (getX()>=gamemap.size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='.' && gamemap[getX()][getY()]->showSymbol()!='#')){
                setX(row);
                ctr++;
            }
        }
        else if (x==2){
            col = getY();
            setY(col+1);
            if (getY()>=gamemap[0].size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='.' && gamemap[getX()][getY()]->showSymbol()!='#')){
                setY(col);
                ctr++;
            }
        }
        else if (x==3){
            row = getX();
            setX(row-1);
            if (getX()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='.' && gamemap[getX()][getY()]->showSymbol()!='#')){
                setX(row);
                ctr++;
            }
        }
        else if (x==4){
            col = getY();
            setY(col-1);
            if (getY()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='.' && gamemap[getX()][getY()]->showSymbol()!='#')){
                setY(col);
                ctr++;
            }
        }
    } while (ctr!=0);
} //implementasi fungsi pure virtual dari parent

string Cow::sound(){
    return "moo";
}

FarmProduct Cow::produceMeat(){
    return CowMeat();
}

FarmProduct Cow::produceMilk(){
    return CowMilk();
}