#include <iostream>
using namespace std;

const int stacksize = 6;

class Stack {
private:
    int top;
    int stack[stacksize];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == stacksize - 1);
    }

    void push(int element) {
        if (isFull()) {
            cout << "Stack over flow error";
            cout << endl;
        }
        else {
            top = top + 1;
            stack[top] = element;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack over flow error";
            cout << endl;
            return -1;
        }
        else {
            int top_item = stack[top];
            top = top - 1;
            return top_item;
        }
    }

    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty";
            cout << endl;
            return -1;
        }
        else {
            return stack[top];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty";
            cout << endl;
        }
        else {
            cout << "Stack elements: ";
            for (int j = top; j >= 0; j--) {
                cout << stack[j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack Stack;

    Stack.push(10);
    Stack.push(15);
    Stack.pop();
    Stack.push(20);
    Stack.push(25);
    Stack.push(30);

    Stack.display(); 

    cout << "Stack top: " << Stack.Top();
    cout << endl;
    Stack.pop();
    Stack.pop();
    Stack.display(); 

    cout << "Stack top: " << Stack.Top(); 
    cout << endl;
}