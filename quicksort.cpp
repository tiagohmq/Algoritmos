#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoarePartition(vector<int> &arr, int left, int right) {
    int p = arr[left];
    int i = left;
    int j = right + 1;

    do {
        // Avança i até achar arr[i] >= p ou i >= right
        do {
            i++;
        } while (i < right && arr[i] < p);

        // Retrocede j até achar arr[j] <= p
        do {
            j--;
        } while (arr[j] > p);

        // Troca se i ainda não cruzou j
        swap(arr[i], arr[j]);

    } while (i < j);

    // Desfaz a última troca, pois i >= j
    swap(arr[i], arr[j]);

    // Coloca o pivot na posição correta
    swap(arr[left], arr[j]);

    return j;
}

void quicksort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int s = hoarePartition(arr, left, right);
        quicksort(arr, left, s - 1);
        quicksort(arr, s + 1, right);
    }
}

int main() {
    cout << "Digite o tamanho do array que voce quer ordenar: ";
    int n; cin >> n;

    cout << "Digite os elementos do array: ";

    int left = 0; int right = n - 1;

    vector<int> arr(n);
    for (int k = 0; k < n; k++) {
    cin >> arr[k];

    }


    quicksort(arr, left, right);
    cout << "Array ordenado: ";
    printArray(arr);

    return 0;
     

}   


