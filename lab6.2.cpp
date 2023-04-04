#include <iostream>
using namespace std;

struct Node {
    int element;
    Node* next;
};

struct Stack {
    Node* head;
    Node* top;
};

void push(Stack& Stack, int n) {
    Node* new_node = new Node{ n, nullptr };
    if (Stack.head == nullptr) {
        Stack.head = new_node;
        Stack.top = new_node;
    }
    else {
        Stack.top->next = new_node;
        Stack.top = new_node;
    }
}

int pop(Stack& Stack) {
    if (Stack.top == nullptr) {
        cout << "Stack is empty";
        cout << endl;
        return -1; 
    }
    else {
        int x = Stack.top->element;
        if (Stack.top == Stack.head) {
            Stack.top = nullptr;
            Stack.head = nullptr;
        }
        else {
            Node* temp = Stack.head;
            while (temp->next != Stack.top) {
                temp = temp->next;
            }
            temp->next = nullptr;
            Stack.top = temp;
        }
        return x;
    }
}

bool empty(Stack& Stack) {
    return (Stack.top == nullptr);
}

bool full(Stack& Stack) {
    return false; 
}

int stack_top(Stack& Stack) {
    if (Stack.top == nullptr) {
        cout << "Stack is empty";
        cout << endl;
        return -1; 
    }
    else {
        return Stack.top->element;
    }
}

void display(Stack& Stack) {
    if (Stack.top == nullptr) {
        cout << "Stack is empty";
        cout << endl;
    }
    else {
        Node* current = Stack.head;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->element << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    Stack Stack{ nullptr, nullptr };
    push(Stack, 10);
    push(Stack, 15);
    pop(Stack);
    push(Stack, 20);
    push(Stack, 25);
    pop(Stack);
    full(Stack);
    empty(Stack);
    display(Stack);
    cout << "Top of the Stack is : " << stack_top(Stack) << endl;
    cout << "Popped element: " << pop(Stack) << endl;
    display(Stack);
}