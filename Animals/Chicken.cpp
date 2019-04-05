#include "Chicken.h"

Chicken::Chicken(int x, int y, bool l): FarmAnimal(x,y,l), EggProducing(x,y,l), MeatProducing(x,y,l){
    if (lapar) simbol = 'c';
    else simbol = 'C';
    threshold = 8;
}

void Chicken::move(){
    int row, col;
    int arr[4] = {1,2,3,4};
    srand(time(0));
    random_shuffle(begin(arr), end(arr));
    for (int x=0; x<4; x++){
        if (arr[x]==1){
            row = getX();
            setX(row+1);
            if (getX()>=gamemap.size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                setX(row);
            }
            else break;
        }
        else if (arr[x]==2){
            col = getY();
            setY(col+1);
            if (getY()>=gamemap[0].size() || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                setY(col);
            }
            else break;
        }
        else if (arr[x]==3){
            row = getX();
            setX(row-1);
            if (getX()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                setX(row);
            }
            else break;
        }
        else if (arr[x]==4){
            col = getY();
            setY(col-1);
            if (getY()<0 || gamemap[getX()][getY()]->getOverrideSymbol()!='\0' || (gamemap[getX()][getY()]->showSymbol()!='o' && gamemap[getX()][getY()]->showSymbol()!='*')){
                setY(col);
            }
            else break;
        }
    }
} //implementasi fungsi pure virtual dari parent

void Chicken::eat(){
    if (threshold<=0 && !lapar) revLapar();
    if (lapar && gamemap[getX()][getY()]->showSymbol()=='*'){
        gamemap[getX()][getY()]->ungrowGrass();
        revLapar();
        threshold = 8;
    }
}

string Chicken::sound(){
    return "petok";
} //suara 'petok'

FarmProduct Chicken::produceEgg(){
    return ChickenEgg();
}

FarmProduct Chicken::produceMeat(){
    return ChickenMeat();
}
