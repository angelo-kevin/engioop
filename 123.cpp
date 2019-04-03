#include <iostream>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main(){
  string command = "";
  cin >> command;
  transform(command.begin(), command.end(), command.begin(), ::tolower);
  cout << command;
  return 0;
}
