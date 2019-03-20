
template<class T>
class Node{
    private:
        Node<T>* next;
        T data;
        int idx;
    public:
        friend class LinkedList;
};

template<class T>
class LinkedList{
    private:
        Node<T>* head;
        int length;
    public: 
        LinkedList(); //constructor
        LinkedList(LinkedList&)
        ~LinkedList(); //destructor
        int find(T); //mengembalikan idx ditemukan data
        bool isEmpty(); //mengembalikan true jika head=NULL atau sebaliknya
        void add(T); //menambah elemen di index paling belakang dari LinkedList
        void remove(T); //mengahapus elemen T tertentu dari LinkedList
        T get(int); //mengembalikan data dari LinkedList di idx tertentu

};