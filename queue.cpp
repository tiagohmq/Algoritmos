#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class queue {
    private:

    Node* front;
    Node* rear;
    size_t size;

    public:

    queue* createQueue() {
        Node* sentinel = new Node;
        sentinel -> val = 0;
        sentinel -> next = nullptr;

        queue* Queue = new queue;
        Queue -> front = sentinel;
        Queue -> rear = sentinel;
        Queue -> size = 0;

        return Queue;

    }

    void enqueue(queue* Queue, int number) {
        Node* NewNode = new Node;
        NewNode -> val = number;
        NewNode -> next = nullptr;

        Queue -> rear -> next = NewNode;
        Queue -> rear = NewNode;
        Queue -> size++;

    }

    int dequeue(queue* Queue) {
        if (Queue -> size == 0) {
            return;    
        }

        Node* removed = Queue -> front -> next;
        Queue -> front -> next = removed -> next;

        if (Queue -> front -> next == nullptr) {
            Queue -> rear = Queue -> front;

        }

        Queue -> size--;

        return removed -> val;
    }





};