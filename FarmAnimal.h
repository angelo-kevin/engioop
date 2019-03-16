#include <string>
using namespace std;

class FarmAnimal{
    private:
        int no; //nomor urut dari objek yang dibentuk dari kelas ini
        char simbol; //menyatakan representasi objek dari kelas ini di map
        int threshold; //menyatakan waktu 'lapar'nya objek dari class ini
    public:
        virtual void Move(); //bergerak secara acak sebesar 1 satuan ke kiri, kanan, atas, maupun bawah
        virtual void Sound() = 0; //method pure virtual, mengeluarkan suara
        bool Lapar(); //mengecek apakah objek dari kelas ini lapar atau tidak
        virtual string Produce() = 0; //menghasilkan produk yang direpresentasikan dengan string

        //Getter setter
        char getSimbol(); //mengembalikan nilai simbol
        int getNo(); //mengembalikan nilai nomor urut objek
        void setSimbol(); //mengubah nilai simbol dari objek yang akan ditunjukkan di map
        int getThreshold(); //mengembalikan nilai threshold dari objek
};

class EggProducing: public FarmAnimal{
    public:
        virtual string Produce(); //implementasi dari method Produce() pada kelas abstrak FarmAnimal
};

class MeatProducing: public FarmAnimal{
    public:
        virtual string Produce(); //implementasi dari method Produce() pada kelas abstrak FarmAnimal
};

class MilkProducing: public FarmAnimal{
    public:
        virtual string Produce(); //implementasi dari method Produce() pada kelas abstrak FarmAnimal
};

class Chicken: public EggProducing, public MeatProducing{
    public:
        string Produce(); //menghasilkan 'telur' dan 'daging'
        void Sound(); //suara 'petok'
};

class Duck: public EggProducing, public MeatProducing{
    public:
        string Produce(); //menghasilkan 'telur' dan 'daging'
        void Sound(); //suara 'kwek'
};

class Cow: public MeatProducing, public MilkProducing{
    public:
        string Produce(); //menghasilkan 'susu' dan 'daging'
        void Sound(); //suara 'moo'
};

class Goat: public MeatProducing, public MilkProducing{
    public:
        string Produce(); //menghasilkan 'susu' dan 'daging'
        void Sound(); //suara 'mbek'
};

class Horse: public MeatProducing{
    public:
        string Produce(); //menghasilkan 'daging'
        void Sound(); //suara 'neigh'
};

class Pig: public MeatProducing{
    public:
        string Produce(); //menghasilkan 'daging'
        void Sound(); //suara 'oink'
};