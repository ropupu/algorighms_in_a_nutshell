// INSERTION SORT SUMMARY
// Best: O(n)    Average, Worst: O(n2)
#include <iostream>

using namespace std;

class InsertionSort {
    public:
        void sort(int arr[], int size) {
            for (int i = 1; i < size; i++) {
                insert(arr, i, arr[i]);
            }
        }
    private:
        void insert(int arr[], int position, int value) {
            int i = position - 1;
            while (i >= 0 && arr[i] > value) {
                arr[i+1] = arr[i];
                i--;
            }
            arr[i+1] = value;
        }
};

int main () {
    InsertionSort sort;
    int data[] = {3, 4, 1, 2, 5};
    sort.sort(data, 5);
    for (int i=0; i < 5; i++) {
        cout << data[i];
    }
    return 0;
}