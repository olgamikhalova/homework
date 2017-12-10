#include <iostream>
#include <stdlib.h>

using namespace std;

class Queue{
public:
    int q[10];
    int* startOfQueue;
    int* endOfQueue;

    Queue(){
        startOfQueue = q;
        endOfQueue = q;
    }

    void put(int n){
        if(endOfQueue - startOfQueue >= 10){
            cout << "Queue overflow";
            exit(-1);
        }
        *endOfQueue = n;
        endOfQueue++;
    }

    int get(){
        if(endOfQueue - startOfQueue == 0){
            cout << "Oops, queue is empty";
            exit(-1);
        }
        int d = *startOfQueue;
        startOfQueue++;
        return d;
    }

    bool isEmpty(){
        return startOfQueue == endOfQueue;
    }
};

int main()
{
    Queue q;
    cout << "Queue is empty? " << q.isEmpty() << endl;
    q.put(1);
    q.put(2);
    q.put(3);
    q.put(4);
    q.put(5);
    q.put(6);
    q.put(7);
    q.put(8);
    q.put(9);
    q.put(10);
    //q.put(11);
    cout << "Queue is empty? " << q.isEmpty() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    cout << " - " << q.get() << endl;
    //cout << " - " << q.get() << endl;

    cout << "Queue is empty? " << q.isEmpty() << endl;
    return 0;
}
