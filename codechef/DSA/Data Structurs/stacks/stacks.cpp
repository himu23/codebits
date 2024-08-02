//lifo //last in first out
//push; pop; peek(inspecting the element at the top of the stack without modifing the stack itself)
//check whether the stack is empty before attempting to pop, which would be an error since there's nothing to remove.
//you only have access to the topmost element;
//This makes the stack an ideal structure for certain applications, such as undo mechanisms in software, function call stacks in programming languages, and parsing expressions in compilers.

//infinix and postfix
//backtracking : dfs

//stl has buildin class stack that has methods like push, top, pop,etc;
#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;

void push(int ele){
    if(top <= MAX_SIZE - 1){ // Remove __ and complete the push function
        a[++top] =  ele;
        cout<<"Pushed: "<<ele<<"\n";
    }
    else{
        cout<<"Stack is full. Cannot push: "<<ele<<"\n";
    }
}

int pop(){
    if(top >= 0){
        int ele = a[top];
        top--; // Remove __ and complete the pop function
        cout<<"Popped: "<<ele<<"\n";
        return ele;
    }
    else{
        cout<<"Stack is empty. Cannot pop.\n";
        return '-1';
    }
}

int peek(){
    if(top >= 0){
        int ele = a[top];
        cout<<"Peeked: "<<ele<<"\n";
        return 1;
    }
    else{
        cout<<"Stack is empty. Cannot peek.\n";
        return 0;
    }
}

int isEmpty(){
    return top == -1;
}

int isFull(){
    if(top >= MAX_SIZE){
        return 1;
    }
    else{
        return 0;
    }
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
        //unused
    }
    return 0;
}