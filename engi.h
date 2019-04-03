#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include "LinkedList.h"
#include "Cell.h"
#include "Cell.cpp"

#include "Lands/Land.h"
#include "Facilities/Facility.h"

//tile-types:
#include "Lands/TileTypes/Barn.h"
#include "Lands/TileTypes/Grassland.h"
#include "Lands/TileTypes/Coop.h"
#include "Lands/TileTypes/Barn.cpp"
#include "Lands/TileTypes/Grassland.cpp"
#include "Lands/TileTypes/Coop.cpp"
//facility-types:
#include "Facilities/FacilityTypes/Mixer.h"
#include "Facilities/FacilityTypes/Well.h"
#include "Facilities/FacilityTypes/Truck.h"
#include "Facilities/FacilityTypes/Mixer.cpp"
#include "Facilities/FacilityTypes/Well.cpp"
#include "Facilities/FacilityTypes/Truck.cpp"

#include "Product/FarmProduct.h"
#include "Product/Product.h"
#include "Product/SideProduct.h"