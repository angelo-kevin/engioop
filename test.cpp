#include <iostream>
#include <vector>
#include <algorithm>

struct compare
{
	int key;
	compare(int const &i): key(i) { }

	bool operator()(int const &i)
	{
		return (i == key);
	}
};

int main()
{
	std::vector<int> v = { 4, 7, 5, 2, 6, 9 };
	int key = 6;

	if (std::find_if(v.begin(), v.end(), compare(key)) != v.end())
		std::cout << "Element found";
	else
		std::cout << "Element not found";

	return 0;
}


/*
#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout<<"const A"<<endl;
        }
        
        virtual void Print(){
            cout<<"hi A!"<<endl;
        }

        virtual void Print2(){
            cout<<"hi A!"<<endl;
        }

};

class B : public A{
    public:
        B(){
            cout<<"const B"<<endl;
        }

        void Print(){
            cout<<"Hi B ! "<<endl;
        }
};

class C : public A{
    public:
        C(){
            cout<<"const C"<<endl;
        }

        void Print2(){
            cout<<"Hi C!"<<endl;
        }
};


void process(A* a){
    a->Print();
}

int main(){
    //B *b = new B;
    A *a = new B;
    //a=b;
    process(a);
    a->Print();

    return 0;
}
*/