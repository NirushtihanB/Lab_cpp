#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// stack implement using array
const int stacksize = 10;

class Arr_Stack {
private:
    int top;
    int stack[stacksize];

public:
    Arr_Stack() {
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

// stack implement using linkedlist
struct Node {
    int element;
    Node* next;
};

struct linkedlist_stack {
    Node* head;
    Node* top;
};

void push(linkedlist_stack& Stack, int n) {
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

int pop(linkedlist_stack& Stack) {
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

bool empty(linkedlist_stack& Stack) {
    return (Stack.top == nullptr);
}

bool full(linkedlist_stack& Stack) {
    return false; 
}

int stack_top(linkedlist_stack& Stack) {
    if (Stack.top == nullptr) {
        cout << "Stack is empty";
        cout << endl;
        return -1; 
    }
    else {
        return Stack.top->element;
    }
}

void display(linkedlist_stack& Stack) {
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
   // using array
   Arr_Stack stack1;
   auto start1 = high_resolution_clock::now();
    stack1.push(5);
    stack1.push(11);
    stack1.push(5);
    stack1.push(9);
    stack1.push(20);
    stack1.push(23);
    stack1.pop();
    stack1.push(7);
    stack1.push(25);
    stack1.push(20);
    stack1.push(3);
    stack1.pop();
    stack1.pop();
    stack1.display();
    stack1.display();
    stack1.push(4);
    stack1.push(30);
    stack1.push(3);
    stack1.pop();
    stack1.push(1);
    stack1.display();
    stack1.pop();
    auto stop1 = high_resolution_clock::now();
    auto duration_1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Execution time using LinkedList: " << duration_1.count() << " microseconds"; 
    cout << endl;


    //using linked list
    linkedlist_stack stack2{ nullptr, nullptr };
   auto start2 = high_resolution_clock::now();
    push(stack2,5);
    push(stack2,11);
    push(stack2,5);
    push(stack2,9);
    push(stack2,20);
    push(stack2,23);
    pop(stack2);
    push(stack2,7);
    push(stack2,25);
    push(stack2,20);
    push(stack2,3);
    pop(stack2);
    pop(stack2);
    display(stack2);
    display(stack2);
    push(stack2,4);
    push(stack2,30);
    push(stack2,3);
    pop(stack2);
    push(stack2,1);
    display(stack2);
    pop(stack2);
    auto stop2 = high_resolution_clock::now();
    auto duration_2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Execution time using LinkedList: " << duration_2.count() << " microseconds"; 






}