#include <iostream>
using namespace std;

template<class T>
class LinkedList;

template<class T>
class Node{
    private:
        Node<T>* next;
        T data;
        int idx; //start from 0 to length-1
    public:
        friend class LinkedList<T>;
        Node(T _data, int _idx){
            next = NULL;
            data = _data;
            idx =  _idx;
        }
        Node(const Node<T>& node){ //copy constructor
            if (!node.isNextEmpty()){
                next = new Node<T>(*(node.next));
            }else{
                next = NULL;
            }
            data = node.data;
            idx = node.idx;
        }
        ~Node(){
            if (next!=NULL)
                delete next;
        }
        bool isNextEmpty(){
            return (next==NULL);
        }
        void Print(){
            //cout<<"Node :"<<endl;
            cout<<"   idx : "<<idx<<endl;
            cout<<"   data : "<<data<<endl;
        }
};

template<class T>
class LinkedList{
    private:
        Node<T>* head;
        int length;
    public: 
        LinkedList() //constructor
        {
            //cout<<"HHmm"<<endl;
            head = NULL;
            length = 0;
        }
        LinkedList(const LinkedList<T>& L){
            head = new Node<T>(*(L.head));
            length = L.length;
        }
        ~LinkedList() //destructor
        {
            if (head!=NULL)
                delete head;
        }

        int find(T _data, bool* visited)
        {  //mengembalikan idx ditemukan data
            Node<T>* ptr = head;
            if(ptr!=NULL){
                int i=0;
                while(ptr->idx < length-1 && ptr->data!=_data) {
                    ptr=ptr->next;
                    i++;
                }
                if (ptr->data == _data && !visited[i]) return ptr->idx;
                else return -1; //not found;
            }else{
                return -1;
            }
        }

        bool isEmpty(){ //mengembalikan true jika head=NULL atau sebaliknya{
            return (head==NULL);
        }

        void add(T _data) //menambah elemen di index paling belakang dari LinkedList
        {
            if (head == NULL){
                head = new Node<T>(_data,0);
            }else{
                Node<T>* ptr = head;
                while (ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next = new Node<T>(_data,ptr->idx+1);
            }
            length++;
        }

        bool foundAll(T* _data, int* index, int size) // initialization : _data and index has been set the size
        { //return whether all item is found and array index of each data found 
            Node<T>* ptr = head;
            if (_data==NULL){
                return 1;
            }else if (ptr!=NULL){
                int i=0;
                bool visited[length];
                for (int i=0;i<length;i++){
                    visited[i]=0;
                }
                //cout<<"size : "<<size<<endl;
                while(find(*(_data+i),visited)!=-1){ //bug
                    
                    *(index+i)=find(*(_data+i),visited); //bug
                    visited[*(index+i)]=1;
                    i++;
                    /*
                    cout<<"VISITED : ";
                    for (int i=0;i<length;i++){
                        cout<<visited[i]<<" ";
                    }
                    cout<<endl;*/
                    /*
                    if (_data+i==NULL){
                        cout<<"MAsuk"<<*(_data+i)<<endl;
                    }
                    */
                }
                
                return (i==size); //all item found
            }else{//list is empty
                return 0;
            }

        }
        
        void resetIndexing(){
            Node<T>* ptr = head;
            int i=0;
            while(ptr!=NULL){
                ptr->idx=i++;
                ptr=ptr->next;
            }
        }

        void remove(T* _data, int size) //menghapus data index ke-idx
        {
            int* idx= new int (size);
            Node<T>* ptr = head;
            /*
            cout<<"DATA : ";
            for (int i=0;i<3;i++){
                cout<<_data[i]<<" ";
            }
            cout<<endl;*/

            if (foundAll(_data,idx,size)){
                int i=0;
                while (i!=size){
                    removeByIdx(*(idx+i));
                    i++;
                    length--;
                }
                resetIndexing();
            }else{
                cout<<"Invalid remove due to incompleteness.."<<endl;
            }
        }

        void removeByIdx(int idx) //initialize: idx certainly part of the list
        {
            Node<T>* ptr = head;
            Node<T>* delNode;
            if (ptr->idx==idx){ //at first element found
                delNode=ptr;
                head=ptr->next;
            }else{
                while (ptr->next!=NULL && ptr->next->idx!=idx){
                    ptr=ptr->next;
                }
                delNode=ptr->next;
                ptr->next=ptr->next->next;
            }
            delNode->next=NULL;
            delete delNode;
        }

        /*
        void remove(T _data) //mengahapus elemen T pertama dari LinkedList
        {

            if(head!=NULL){
                Node* ptr = head;

                if (ptr->data==_data){

                }
                if (!ptr->isNextEmpty()){
                    while((ptr->next)->idx < length && (ptr->next)->data!=_data) {
                        ptr=ptr->next;
                    }
                    //last element
                    if (ptr->next->data == _data){
                        Node* ptrdel = ptr->next;
                    
                        if (ptr->next->next == NULL){ //at the last of elements
                            ptr->next=NULL;
                        }else{
                            ptr->next = ptr->next->next;
                            ptr = ptr->next;
                            while(ptr!=NULL){
                                ptr->id-=1;
                                ptr=ptr->next;
                            }
                        }
                        delete ptrdel;
                    }else{
                        cout<<"Data not found!"<<endl;
                    }
                }else{ //contain only one element
                    
                }
                    
            }
        }*/


        T get(int _idx) //assume idx is in range //mengembalikan data dari LinkedList di idx tertentu
        {
            if (_idx>=length){
                cout<<"index out of range"<<endl;
                return T(); 
            }else{
                Node<T>* ptr=head;
                while(ptr->idx < length && ptr->idx!=_idx) {
                    ptr=ptr->next;
                }
                // if (ptr->idx == _idx) 
                return ptr->data;
            }
        }

        void Print(){
            Node<T>* ptr = head;
            if (ptr==NULL){
                cout<<"List Empty"<<endl;
            }else{
                cout<<"Length : "<<length<<endl;
                while(ptr!=NULL){
                    cout<<"Node : "<<endl;
                    ptr->Print();
                    ptr=ptr->next;
                }
            }
        }

};

