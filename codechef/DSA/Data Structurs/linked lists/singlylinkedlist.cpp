//Linked list is a linear data structure where each element is a separate object connected to each other and is similar to Arrays.
//each node contains two fields: value(integer) and pointer to next node
//last node is called tail. its next pointer is null, indicating there is no element after it.
//insertion, deletion, display
//done by using a node class for each node of the linked list
#include <iostream>
using namespace std;

// Create a struct with two values
struct Node {
    int value;
    Node* next;
    
    // Constructor to initialize the node with a given value
    Node(int val): value(val), next(nullptr) {}
};

int main() {
    // Creating head of the Linked list
    Node* head = new Node(1);
    cout << "The value at head is " << head -> value << endl;
}

//in cpp the 'new' keyworad is used to dynaamically allocate memory for a variable or object at runtime.
// it allocates memory form the heap(free store) and returns  pointer to the allocated memory.