#include "EggProducing.h"

EggProducing::EggProducing(int x, int y, bool l): FarmAnimal(x,y,l){}

string EggProducing::produceegg(){
    return "telur";
}
string EggProducing::produce(){
     return "I produce egg";
 }