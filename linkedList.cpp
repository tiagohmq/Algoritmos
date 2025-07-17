#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class linkedlist {
    private:
    
    Node* head;
    Node* tail;
    Node* cur;
    size_t size;

    public:

    linkedlist* createList() {
        linkedlist* list = new linkedlist;
        list -> head = new Node;
        head -> next = nullptr;
        list -> cur = list -> head;
        list -> tail = list -> head;
        list -> size = 0;

        return list;
    }

    void append(linkedlist* list, int number) {
        Node* NewNode = new Node;
        NewNode -> val = number;
        NewNode -> next = list -> cur -> next;
        list -> cur -> next = NewNode;

        if (list -> tail = list -> cur) {
            list -> tail = NewNode;
        }

        list -> size++;
    }

    int remove(linkedlist* list) {
        if (list -> cur -> next == nullptr) {
            return;
        }

        Node* removed = list -> cur -> next;
        list -> cur -> next = removed -> next;
        if (list -> tail = removed) {
            list -> tail = list -> cur;
        }
        list -> size--;

        return removed -> val;
    }

    void moveToStart(linkedlist* list) {
        list -> cur = list -> head;
    }

    void moveToEnd(linkedlist* list) {
        list -> cur = list -> tail;
    }

    void moveToNext(linkedlist* list) {
        if (list -> cur != list -> tail) {
            list -> cur = list -> cur -> next;
        }
    }

    void moveToPrevious(linkedlist* list) {
        if (list -> cur = list -> head) {
            return;
        }

        Node* temp = list -> head;
        while(temp -> next != list -> cur) {
            temp = temp -> next;
            list -> cur = temp;
        }
    }

};

