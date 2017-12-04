#include <iostream>

using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* firstNode = NULL;

    void addNonFirstNode(int n, Node* node){
        if (node->next != NULL){
            addNonFirstNode(n, node->next);
        } else {
            node->next = new Node(n);
            node->next->data = n;
            node->next->next = NULL;
        }
    }

    void add(int n){
        if (firstNode == NULL){
            firstNode = new Node(n);
            firstNode->data = n;
            firstNode->next = NULL;
        } else {
            addNonFirstNode(n, firstNode);
        }
    }

    void add(Node* node, int index, int n, int counter = 0){
        if (index == 0){
			Node* newFirstNode = new Node(n);
			newFirstNode->next = node;
			firstNode = newFirstNode;
			return;
		}
        if(counter < index - 1){
            add(node->next, index, n, ++counter);
            return;
        }

        Node* temp = node->next;
        node->next = new Node(n);
        node->next->next = temp;

    }

    void remove(Node* &node, int index){
        if (!node)
            return;
		if (index == 0) {
			node = node->next;
			return;
		}
		remove(node->next, index - 1);
	}

	int get(Node* node, int index){
		if (node == NULL){
            return(0);
		}
		if (index == 0){
			return(node->data);
		} else {
			return(get(node->next, index - 1));
        }
	}

    void show(Node* n){
        cout << n->data << endl;
        if(n->next != NULL){
            show(n->next);
        }
    }
};

int main(){
    LinkedList l;
    l.add(12);
    l.add(24);
    l.add(27);
    l.add(30);
    l.add(35);
    l.add(37);
    l.show(l.firstNode);
    cout << "++++++++++++++++++++++" << endl;
    l.remove(l.firstNode, 2);
    l.show(l.firstNode);
    cout << "++++++++++++++++++++++" << endl;
    cout << l.get(l.firstNode, 2) << endl;
    cout << "++++++++++++++++++++++" << endl;
    l.add(l.firstNode, 3, 50);
    l.show(l.firstNode);

    return 0;
}
