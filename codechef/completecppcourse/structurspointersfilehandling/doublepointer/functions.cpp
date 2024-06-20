#include <iostream>
using namespace std;

void swap(int** a, int** b) {
    // Update the function to solve the problem
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int a = 10, b = 5;

    int* c = &a;
    int* d = &b;

    swap(&c, &d);

    cout << a << " " << b << "\n";

    return 0;
}

//value stored in a pointer that is uninitialised is garbage value.