#include <iostream>
#include <stdlib.h>

using namespace std;

class Stack{
public:
    int stackArray[10];
    int* last;
    int* first;

    Stack(){
       last = stackArray;
       first = stackArray;
    }

    void put(int n){
        if(last - first >= 10){
            cout << "Stack overflow";
            exit(-1);
        }
        *last = n;
        last++;
    }

    int get(){
        if(last - first == 0){
            cout << "Oops, stack is empty";
            exit(-1);
        }
        --last;
        int d = *last;
        return d;
    }

    bool isEmpty(){
        return (last == first);
    }
};

int main()
{
    Stack s;
    cout << "Stack is empty? " << s.isEmpty() << endl;

    s.put(1);
    s.put(2);
    s.put(3);
    s.put(4);
    s.put(5);
    s.put(6);
    s.put(7);
    s.put(8);
    s.put(9);
    s.put(10);
    cout << "Stack is empty? " << s.isEmpty() << endl;

   //s.put(11);
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;
    cout << " - " << s.get() << endl;

    //cout << " - " << s.get() << endl;

    cout << "Stack is empty? " << s.isEmpty() << endl;
    return 0;
}
