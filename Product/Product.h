#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product{
//Kelas dari produk yang bisa didapatkan pada progarm. Memiliki kelas turunan FarmProduct dan SideProduct
protected:
  int harga; //Harga dari produk
  string productname; //Nama dari produk
public:
  Product(); //Construct objek Product dengan harga = 0 dan productname = ""
  Product(int price, string name); //Construct objek Product dengan harga = price dan productname = name

  void setHarga(int price); //Set harga produk dengan price
  void setProductName(string name); //Set nama produk dengan name

  int getHarga(); //Fungsi untuk mendapatkan harga produk
  string getProductName(); //Fungsi untuk mendapatkan nama produk
};

#endif
