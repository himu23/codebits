// fifo // first in first out
//meaning that the first element added to the queue is the first one to be removed
//enqueue (or offer): (adding) an element to rear(end) of the queue;
//dequeue (or poll): (removing) and returning the element at the front of the queue.
//support for peeking
//bfs
#include <bits/stdc++.h>
using namespace std;

#define maxSize 101
int a[maxSize];
int front = 0; // Index of the front element
int rear = -1;  // Index of the rear element
int currentSize;

bool isEmpty(){
    return currentSize == 0;
}

bool isFull(){
    return currentSize == maxSize;
}

int size(){
    return currentSize;
}

void enqueue(int item) {
    if (isFull()) {
        cout<<"Queue is full. Cannot enqueue.\n";
        return;
    }
    rear = (rear+1) % maxSize; // Circular increment
    a[rear] = item;
    currentSize++;
}

int dequeue(){
    if (isEmpty()) {
        cout<<"Queue is empty. Cannot dequeue.\n";
        return -1; // Return a sentinel value or throw an exception
    }
    int removedItem = a[front];
    front = (front + 1) % maxSize; // Circular increment
    currentSize--;
    return removedItem;
}

int main(){
    int n = 10;
    // Your code goes here
    for(int i=1;i<=n;i++){
        if(i%2==1){
            cout<<i<<" ";
        }
        else{
            enqueue(i);
        }
        
    }
    while(!isEmpty()){
        cout<<dequeue()<<" ";
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k; k=1;
    cin>>k;
    while(k--){
        int n; cin>>n;
        
    }
    return 0;
}