#include <iostream>
using namespace std;



struct Node {
    int element;
    int key;
    Node* left;
    Node* right;

};

class BST {
    private:

    Node* root;
    int nodecount;

    Node* createNode(int k, int value) { 
        Node* NewNode = new Node;
        NewNode -> key = k;
        NewNode -> element = value;
        NewNode -> left = NULL;
        NewNode -> right = NULL;

        return NewNode;

    }

    BST* createBST() {
        BST* bst = new BST;
        bst -> root = NULL;
        bst -> nodecount = 0;

        return bst;

    }

    Node* getmin(Node* root) {
        if (root -> left == NULL) {
            return getmin(root -> left);
        }
    }

    Node* deletemin(Node* root) {
        if (root -> left == NULL) {
            return root -> right;
        }
        root -> left = deletemin(root -> left);
        return root;
    }

    Node* inserthelp(Node* root, int k, int value) {
        if (root == NULL) {
            return createNode(k, value);
        }
        if (root -> key > k) {
            root -> left = inserthelp(root -> left, k, value);
        }
        else {
            root -> right = inserthelp(root -> right, k, value);
        }
    }

    int findhelp(Node* root, int k) {
        if (root == NULL) {
            return NULL;
        }
        if (root -> key > k) {
            return findhelp(root -> left, k);
        }
        else if (root -> key == k) {
            return root -> element;
        }
        else {
            return findhelp(root -> right, k);
        }

    }

    Node* removehelp(Node* root, int k) {
        if (root == NULL) {
            return NULL;
        }
        if (root -> key > k) {
            root -> left = removehelp(root -> left, k);
        }
        else if (root -> key < k) {
            root -> right = removehelp(root -> right, k);
        }
        else {
            if (root -> left == NULL) {
                return root -> right;
            }
            else if (root -> right == NULL) {
                return root -> left;
            }
            else {
                Node* temp = getmin(root -> right);
                root -> element = temp -> element;
                root -> key = temp -> key;
                root -> right = deletemin(root -> right);
            }
        }

        return root;
    }
        

    public:

    int find(BST* bst, int k) {
        return findhelp(bst -> root, k); {
        }
    }

    void insert(BST* bst, int k, int value) {
        bst -> root = inserthelp(root, k, value);
    }

    int remove(BST* bst, int k) {
        int temp = findhelp(bst -> root, k);
        if (temp =! NULL) {
            removehelp(bst -> root, k);
            nodecount--;
        }
        return temp;
        
    }
};

