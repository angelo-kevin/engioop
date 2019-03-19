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
class LinkedList: public Inventory{
    private:
        Node<T>* head;
        int length;
    public: 
        LinkedList(); 
        ~LinkedList();
        int find(T);
        bool isEmpty();
        void add(T);
        void remove(T);
        T get(int);

};