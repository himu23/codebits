#include <iostream>
using namespace std;

class Node {
    public:
    int value;
    Node* next;
    
    // Constructor to initialize the node with a given value
    Node(int val): value(val), next(nullptr) {}
};

class LinkedList {
    public:
    Node* head;
    
    void insertAfterK(int value, int k) {

        Node* newNode = new Node(value);
        Node* current = head;
    
        // If there are no nodes in the linked list
        // Set the new node as head and return
        if (head == NULL) {
            head = newNode;
            return;
        }
    
        // Iterate to the k-th node
        for (int i = 1; i < k; i++) {
            current = current -> next;
        }
    
        // Set the next of new Node to next of current
        newNode -> next = current -> next;
    
        // Set the next of current to new Node
        current -> next = newNode;
    
    }



    void insertAtEnd(int value) {
        //O(N)
        Node* newNode = new Node(value);
        Node* current = head;
        
        // If there are no nodes in the linked list
        // Set the new node as head and return
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        // Iterate to the end of list
        while (current -> next != NULL) {
            current = current -> next;
        }
        
        // Set the next of last value to the new Node
        current -> next = newNode;
    }

    
    void deletestartNode(int value) {
    
        if (head -> value == value) {
            Node* targetNode = head;
        
            // Set head to the next of targetNode
            head = head -> next;
        
            // Delete the target node
            delete targetNode;
        }
}
    
    int getLastValue() {
        if (head == NULL) {
            return -1;
        } else {
            Node* current = head;
            while (current -> next != NULL) {
                current = current -> next;
            }
            return current -> value;
        }
    }
};

int main() {
    int n;
    cin >> n;
    
    LinkedList* list = new LinkedList();
    
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        list -> insertAtEnd(x);
        cout << list -> getLastValue() << ' ';
    }
}


class LinkedList2 {
    public:
    Node* head;
    
    // Create the Node tail
    Node* tail;

    void insertAtEnd2(int value) {
        //O(1)
        Node* newNode = new Node(value);
        
        // If there are no nodes in the linked list
        // Set the new node as head and return
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        
        // Set next of tail to the new Node
        tail -> next = newNode;
        
        // Set new Node as the new tail
        tail = newNode;
    }

  
    void printValues() {
        if (head == NULL) {
            return;
        } else {
            Node* current = head;
            while (current != NULL) {
                cout << current -> value << ' ';
                current = current -> next;
            }
            cout << '\n';
        }
    }
};