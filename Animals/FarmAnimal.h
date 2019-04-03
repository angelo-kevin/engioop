#ifndef FARMAN_H
#define FARMAN_H
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#include "../Product/FarmProduct.h"

class FarmAnimal{
    protected:
        char simbol; //menyatakan representasi objek dari kelas ini di map
        int threshold; //menyatakan waktu 'lapar'nya objek dari class ini
        bool lapar; //menyatakan status lapar
        int x; //posisi
        int y; //posisi
    public:
        FarmAnimal(int x, int y, bool lapar);
        virtual void move() = 0; //bergerak secara acak sebesar 1 satuan ke kiri, kanan, atas, maupun bawah
        virtual string sound() = 0; //method pure virtual, mengeluarkan suara
        virtual FarmProduct producemeat() = 0;
        virtual FarmProduct produceegg() = 0;
        virtual FarmProduct producemilk() = 0;

        //Getter setter
        char showSimbol(); //mengembalikan nilai simbol
        void revSimbol(); //mengubah nilai simbol dari objek yang akan ditunjukkan di map
        int getThreshold(); //mengembalikan nilai threshold dari objek
        bool getLapar(); //mengecek apakah objek dari kelas ini lapar atau tidak
        void revLapar(); //mengubah nilai lapar dari objek
        int getX();
        int getY();
};

#endif