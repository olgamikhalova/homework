#include <iostream>
#include <cstring>

using namespace std;

class Map{
public:
    int array[100];

    int hash(char* str){
        return strlen(str);
    }

    int get(char* str){
        return array[hash(str)];
    }

    void put(char* str, int data){
        array[hash(str)] = data;
    }
};

int main()
{
    Map m;
    m.put("masha", 23);
    cout << m.get("masha") << endl;
    m.put("lena", 28);
    cout << m.get("lena") << endl;

    return 0;
}
