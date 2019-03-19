#include <bits/stdc++.h>
#include "Landtypes.h"
using namespace std;

class FarmAnimal{
    protected:
        char simbol; //menyatakan representasi objek dari kelas ini di map
        int threshold; //menyatakan waktu 'lapar'nya objek dari class ini
        bool lapar; //menyatakan status lapar
        int x; //posisi
        int y; //posisi
    public:
        FarmAnimal(int x, int y, bool lapar); //ctor
        virtual void move(vector<vector<Cells*> > maps) = 0; //bergerak secara acak sebesar 1 satuan ke kiri, kanan, atas, maupun bawah
        virtual void sound() = 0; //method pure virtual, mengeluarkan suara
        virtual string produce() = 0; //menghasilkan produk yang direpresentasikan dengan string

        //Getter setter
        char showSimbol(); //mengembalikan nilai simbol
        void revSimbol(); //mengubah nilai simbol dari objek yang akan ditunjukkan di map
        int getThreshold(); //mengembalikan nilai threshold dari objek
        bool getLapar(); //mengecek apakah objek dari kelas ini lapar atau tidak
        void setLapar(); //mengubah nilai lapar dari objek
        int getX();
        int getY();
};