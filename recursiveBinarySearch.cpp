#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool binarySearch(const vector<int>& array, int numberWanted, int start, int end) {
    if (start > end) {
        return false;
    }
    int middle = start + (end - start) / 2;
    if (array[middle] == numberWanted) {
        return true;
    } else if (array[middle] < numberWanted) {
        return binarySearch(array, numberWanted, middle + 1, end);
    } else {
        return binarySearch(array, numberWanted, start, middle - 1);
    }
}

int main() {
    vector<int> array = {5, 56, 14, 78, 23, 42, 89, 12, 67, 34, 90, 11, 45, 22, 33, 88, 99, 100, 1, 2, 3};

    
    if (!is_sorted(array.begin(), array.end())) {
        sort(array.begin(), array.end());
        cout << "Array foi ordenado." << endl;
    } else {
        cout << "Array já está ordenado." << endl;
    }

    
    int numberWanted = 42;
    if (binarySearch(array, numberWanted, 0, array.size() - 1)) {
        cout << numberWanted << " encontrado!" << endl;
    } else {
        cout << numberWanted << " não encontrado." << endl;
    }

    return 0;
}