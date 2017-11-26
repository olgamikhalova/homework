#include <iostream>

using namespace std;

class ArrayList{
private:
    const int INIT_SIZE = 10;

	int* array;
    int currentSize;
    int allocatedSize;

    void fillNewArray(int* newArray){
		for (int i = 0; i < currentSize; i++){
			newArray[i] = array[i];
		}
    }

    void addToNotFullArray(int n){
        array[currentSize] = n;
        currentSize++;
    }

    void addToFullArray(int n){
        int* newArray = new int[allocatedSize * 2];
        allocatedSize *= 2;
        fillNewArray(newArray);
        delete []array;
        array = newArray;
        addToNotFullArray(n);
    }

public:
    ArrayList(){
        array = new int[INIT_SIZE];
        currentSize = 0;
        allocatedSize = INIT_SIZE;
    }

    void add(int n){
        if(currentSize < allocatedSize){
            addToNotFullArray(n);
        } else {
            addToFullArray(n);
        }
    }

    void add(int n, int index){
		if (index < currentSize){
			int* newArray = new int[currentSize + 1];
			for (int i = 0; i < index; i++)
				newArray[i] = array[i];
            newArray[index] = n;
			for (int y = index; y < currentSize; y++)
				newArray[y + 1] = array[y];

			delete[]array;
			array = newArray;
			currentSize++;
		} else {
			int* newArray = new int[index + 1];
			for (int i = 0; i < currentSize; i++)
				newArray[i] = array[i];
			for (int i = currentSize; i < index; i++)
				newArray[i] = 0;
			newArray[index] = n;

			delete[]array;
			array = newArray;
			currentSize = index + 1;
		}
    }

    void trimToSize(int index){
		int* newArray = new int[index];

		if (index < currentSize){
			for (int i = 0; i < index; i++)
				newArray[i] = array[i];
		} else{
			for (int i = 0; i < currentSize; i++)
				newArray[i] = array[i];
			for (int i = currentSize; i < index; i++)
				newArray[i] = 0;
		}
		delete[]array;
		array = newArray;
		currentSize = index;
    }

    int get(int index){
        if(index >= currentSize){
            cout<<"Error! Index is out of bound!"<<endl;
            return -1;
        }
        return array[index];
    }

    void remove(int index){
		if (index < currentSize){
			int* newArray = new int[currentSize - 1];

			for (int i = 0; i < index - 1; i++)
				newArray[i] = array[i];
			for (int i = index - 1; i < currentSize - 1; i++)
				newArray[i] = array[i + 1];

			delete[]array;
			array = newArray;
			currentSize--;
		} else
			cout << "Error! Index is out of bound!" << endl;
    }

    void print(){
        for(int i = 0; i < currentSize; i++){
            cout << array[i] << " ";
        }
    }
};

int main(){
    ArrayList* list = new ArrayList();
    for(int i = 0; i < 30; i++){
        list->add(i);
    }
	//list->add(12, 3);
	//list->trimToSize(20);
	//list->remove(20);
	list->print();

	cout << endl;
}
