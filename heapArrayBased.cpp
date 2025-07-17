#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {  // começa do índice 1
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(vector<int> &array) {
    size_t n = array.size() - 1; // base 1: desconsidera o índice 0
    for (int i = n / 2; i >= 1; i--) {
        int fatherNodePos = i;
        int fatherNodeVal = array[fatherNodePos];
        bool isHeap = false;

        while (!isHeap && 2 * fatherNodePos <= n) {
            int childNodePos = 2 * fatherNodePos;
            if (childNodePos < n && array[childNodePos] < array[childNodePos + 1]) {
                childNodePos++;
            }

            if (fatherNodeVal >= array[childNodePos]) {
                isHeap = true;
            } else {
                array[fatherNodePos] = array[childNodePos];
                fatherNodePos = childNodePos;
            }
        }

        array[fatherNodePos] = fatherNodeVal;
    }
}

int main() {
    // Agora o vetor começa do índice 1, como no slide
    vector<int> heapArray = {0, 2, 9, 7, 6, 5, 8, 10};

    cout << "Array original:\n";
    printArray(heapArray);

    heapify(heapArray);

    cout << "Array após heapificado (bottom-up):\n";
    printArray(heapArray);

    return 0;
}
