#include <iostream>

using namespace std;

class ArrayList{
private:
    const int INIT_SIZE = 10;

	int* array;
    int currentSize;
    int allocatedSize;
	int forTrim = -1;

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

    void addToNotFullArrayInIndex(int n, int index){
        currentSize++;
        for (int i = currentSize; i > index; i--){
            array[i] = array[i - 1];
        }
        array[index] = n;
    }

    void addToFullArrayInIndex(int n, int index){
        allocatedSize = index + 1;
        int* newArray = new int[allocatedSize];
        fillNewArray(newArray);

        for (int i = currentSize; i < index; i++){
			newArray[i] = forTrim;
        }

        newArray[index] = n;
        currentSize = index + 1;

        delete []array;
        array = newArray;
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
		if (currentSize + 1 < allocatedSize && index < currentSize + 1){
            addToNotFullArrayInIndex(n, index);
        } else {
            addToFullArrayInIndex(n, index);
        }
    }

	void trimToSize(){
		int x = 0;
		int notMinusOne = 0;

		for (int i = 0; i < currentSize; i++){
			if (array[i] != forTrim){
				notMinusOne++;
			}
		}
		int* newArray = new int[notMinusOne];

		for (int i = 0; i < notMinusOne; i++){
			if (array[x] != forTrim){
				newArray[i] = array[x];
			}
			if (array[x] == forTrim){
				i--;
			}
			x++;
		}

		delete[] array;

		array = newArray;
		currentSize = notMinusOne;
	}

    int get(int index){
        if(index >= currentSize){
            cout << "Error! Index is out of bound!" << endl;
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
	//list->add(7, 35);
	list->trimToSize();
	//list->remove(20);
	list->print();

	cout << endl;
}
