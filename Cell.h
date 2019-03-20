// Base Class : Cell
/* Kelas Cell adalah base class yang merepresentasikan setiap objek-objek yang akan muncul di map, seperti semua objek Facility, objek Land, objek Farm Animal, dan Player. Kelas ini memiliki atribut symbol bertipe char yang unik bagi setiap objek di map dan method getter untuk simbol tersebut.*/
class Cell{
  private:
    // Unique symbol for each objects
    char Symbol;
  public:
    // Base Class Constructor
    Cell();
    // Virtual Method Unique symbol for every types of objects in cell
    char showSymbol();
};
