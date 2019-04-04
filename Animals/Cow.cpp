#include "Cow.h"

Cow::Cow(int x, int y, bool l): FarmAnimal(x,y,l), MilkProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 's';
    else simbol = 'S';
    threshold = 10;
}

void Cow::move(){
    int row, col;
    int arr[4] = {1,2,3,4};
    if (threshold<=0 && !lapar) revLapar();
    if (lapar && gamemap[getX()][getY()]->showSymbol()=='#'){
        gamemap[getX()][getY()]->ungrowGrass();
        lapar = false;
        threshold = 10;
    }
    srand(time(0));
    random_shuffle(begin(arr), end(arr));
    for (int x=0; x<4; x++){
        if (arr[x]==1){
            row = getX();
            setX(row+1);
            if (getX()>=gamemap.size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='.' && gamemap[getX()][getY()]->showSymbol()!='#')){
                setX(row);
            }
            else break;
        }
        else if (arr[x]==2){
            col = getY();
            setY(col+1);
            if (getY()>=gamemap[0].size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='.' && gamemap[getX()][getY()]->showSymbol()!='#')){
                setY(col);
            }
            else break;
        }
        else if (arr[x]==3){
            row = getX();
            setX(row-1);
            if (getX()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='.' && gamemap[getX()][getY()]->showSymbol()!='#')){
                setX(row);
            }
            else break;
        }
        else if (arr[x]==4){
            col = getY();
            setY(col-1);
            if (getY()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='.' && gamemap[getX()][getY()]->showSymbol()!='#')){
                setY(col);
            }
            else break;
        }
    }
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
