#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val): value(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    ~CircularLinkedList() {
        if (head == nullptr) return;
        Node* current = head;
        do {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // Set head and tail as new node
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            // Set next of tail to new Node
            tail->next = newNode;
            // Set tail as new Node
            tail = newNode;
            // Set next of tail to head
            tail->next = head;
        }
    }

    void display() const {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->value << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void deleteNode(int value) {
        // If there is only one element and it is the value to be deleted, remove it
        if (head == tail && head -> value == value) {
            head = NULL;
            tail = NULL;
            return;
        }

        // if the target is at head set head to second element and set tail's next to the new head
        Node* iter = head;
        if (head -> value == value){
            head = head -> next;
            tail -> next = head;
            return;
        }

        // Now iterate over the linked list till you reach the tail and check if the next node is target
        while (iter -> next != NULL && iter != tail){
            if (iter -> next -> value == value)
            {
                // If we found the value
                // Set current node's next to the next of the next node
                iter->next=iter->next->next;

                // And break
                break;
            }
            iter = iter -> next;
        }
    }

};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);

    cll.display();  // Output: 1 2 3

    return 0;
}
