#include <iostream>
#include <queue>

int main() {
    // Creating a queue
    std::queue<int> myQueue;

    // Enqueue elements
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Displaying the front and back elements
    std::cout << "Front element: " << myQueue.front() << std::endl;
    
    // Displaying and removing elements
    std::cout << "Queue elements: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        std::cout << "Back element: " << myQueue.back() << std::endl;
        myQueue.pop();
    }
    std::cout << std::endl;

    // Checking if the queue is empty
    if (myQueue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}
