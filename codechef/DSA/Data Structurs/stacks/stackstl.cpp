#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;
    
    // Adding elements (push)
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Accessing the top element
    int topElement = myStack.top();
    std::cout << "Top element: " << topElement << std::endl;

    // Removing elements (pop)
    myStack.pop();
    topElement = myStack.top();
    std::cout << "Top element after pop: " << topElement << std::endl;
    int sz=myStack.size();
    return 0;
}