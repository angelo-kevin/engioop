#include "LinkedList.h"

int main(){
    LinkedList<int> listOfObject;
    listOfObject.Print();

    listOfObject.add(2);
    listOfObject.add(10);
    listOfObject.add(20);
    listOfObject.add(80);
    listOfObject.add(10);
    listOfObject.Print();

    int data[3] = {20,10,80};
    /*for (int i=0;i<3;i++){
        cout<<data[i]<<" ";
    }*/
    cout<<endl;
    listOfObject.remove(data,3);
    listOfObject.Print();

    cout<<listOfObject.get(10)<<endl;
    return 0;
}