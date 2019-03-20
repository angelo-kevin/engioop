template<class T>
class Node{
    private:
        Node<T>* next;
        T data;
        int idx; //start from 0 to length-1
    public:
        friend class LinkedList;
        Node(T _data, int _idx){
            next = NULL;
            data = _data;
            idx =  _idx;
        }
        Node(Node& node){
            next = new Node(node.next);
            data = node.data;
            idx = node.idx;
        }
        ~Node(){
            delete next;
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
            head = NULL;
            length = 0;
        }
        LinkedList(LinkedList& L){
            head = new Node(L.head);
            length = L.length;
        }
        ~LinkedList() //destructor
        {
            delete head;
        }
        int find(T _data) //mengembalikan idx ditemukan data
        {
            Node* ptr = head;
            while(ptr->idx < length && ptr->data!=_data) {
                ptr=ptr->next;
            }
            if (ptr->data == _data) return ptr->idx
            else return -1; //not found;
        }
        bool isEmpty() //mengembalikan true jika head=NULL atau sebaliknya{
            return (head==NULL);
        }
        void add(T _data) //menambah elemen di index paling belakang dari LinkedList
        {
            if (head == NULL){
                Node node(_data,0);
                head = new Node(node);
            }else{
                Node* ptr = head;
                while (ptr->next!=NULL){
                    ptr=ptr->next;
                }
                Node node(_data, ptr->idx+1)
                ptr->next = new Node(node);
            }
            length++;

        }
        void remove(T _data) //mengahapus elemen T pertama dari LinkedList
        {
            if(head!=NULL){
                Node* ptr = head;
                while(ptr->next->idx < length && ptr->next->data!=_data) {
                    ptr=ptr->next;
                }
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
                }
                
            }
        }
        T get(int _idx); //assume idx is in range //mengembalikan data dari LinkedList di idx tertentu
        {
            Node* ptr=head;
            while(ptr->idx < length && ptr->idx!=_idx) {
                ptr=ptr->next;
            }
            if (ptr->idx == _idx) return ptr->data 
        }

};