#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> array, int numberWanted) {
    int start = 0;
    int end = array.size() - 1;

    while (start <= end) {
        int middle = start + (end - start) / 2;

        if (array[middle] == numberWanted) {
            return true;
        }

        else if (array[middle] < numberWanted) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }

    }
    return false;

}

int main() {
    
    vector<int> array = {/* seus 1024 elementos aqui */};

    // Verifica se está ordenado
    if (!is_sorted(array.begin(), array.end())) {
        sort(array.begin(), array.end());
        cout << "Array foi ordenado." << endl;
    } else {
        cout << "Array já está ordenado." << endl;
    }

    // Exemplo de uso da busca binária
    int numberWanted = 42;
    if (binarySearch(array, numberWanted)) {
        cout << numberWanted << " encontrado!" << endl;
    } else {
        cout << numberWanted << " não encontrado." << endl;
    }

    return 0;
}