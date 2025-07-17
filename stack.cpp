#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class stack {
    private:
    Node* top;
    size_t size;

    public:
    stack* createStack() {
        stack* Stack = new stack;
        Stack -> top = nullptr;
        Stack -> size = 0;

        return Stack;

    }

    void push(stack* Stack, int number) {
        Node* NewNode = new Node;
        NewNode -> val = number;
        NewNode -> next = Stack -> top;
        Stack -> top = NewNode;
        Stack -> size++;

    }

    int pop(stack* Stack) {
        if (Stack -> top == nullptr) {
            return;
        }

        Node* removed = Stack -> top;
        Stack -> top = removed -> next;
        Stack -> size--;

        return removed -> val;
    }

};