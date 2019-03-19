// Base Class : Cell
class Cell{
  private:
    // Unique symbol for each objects
    char Symbol;
  public:
    // Base Class Constructor
    Cell();
    // Virtual Destructor
    virtual ~Cells(){};
    // Virtual Method Unique symbol for every types of objects in cell
    char showSymbol();
};
