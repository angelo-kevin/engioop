// Base Class : Cell
class Cell{
  public:
    // Base Class Constructor
    Cell();
    // Virtual Destructor
    virtual ~Cells(){};
    // Virtual Method Unique symbol for every types of objects in cell
    virtual char showSymbol()=0;
};
