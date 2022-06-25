#include <iostream>

using namespace std;

class QuickSort {
public:
    QuickSort() {
        cout << "Constructor" << endl;
    }
    ~QuickSort() {
        cout << "Destructor" << endl;
    }
    void InsertRun();
    void Swap(int&, int&);
    void Print(int[], int);
    int Partition(int[], int, int);
    void Quicksort(int[], int, int);
};
void QuickSort::InsertRun() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    if (n < 0) {
        cout << "Error! Enter only positive numbers: " << endl;
    }
    if (n == 0) {
        cout << "Error! Array can't be empty" << endl;
    }
    int* arr = new int[n];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Quicksort(arr, 0, n - 1);
    Print(arr, n);
}
void QuickSort::Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort::Print(int arr[], int size) {
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int QuickSort::Partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start+1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pIndex = start + count;
    swap(arr[pIndex], arr[start]);
    int i = start, j = end;
    while (i < pIndex && j > pIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pIndex && j > pIndex)
            swap(arr[i++], arr[j--]);
    }
    return pIndex;
}

void QuickSort::Quicksort(int arr[], int start, int end) {
    if (start < end) {
        int q = Partition(arr, start, end);
        Quicksort(arr, start, q - 1);
        Quicksort(arr, q + 1, end);
    }
}
int main() {
    QuickSort q;
    q.InsertRun();
    return 0;
}