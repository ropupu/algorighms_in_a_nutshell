// QUICK SORT SUMMARY
// Best, Average: O(nlogn) Worst: O(n2)
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class QuickSort {
    public:
        void sortPointers(int *arr[], int size) {
            quicksort(arr, 0, size - 1);
        }
    private:
        void quicksort(int *arr[], int left, int right) {

            if (left < right) {
                int pivot = partition(arr, left, right);
                quicksort(arr, left, pivot);
                quicksort(arr, pivot + 1, right);
            }
        }
        int partition(int *arr[], int left, int right) {
            // select pivot
            int pivot = (left + right) / 2;

            int* pivotValue = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = pivotValue;
            int newPivotPosition = left;
            int* tmp;
            for (int i = left; i < right; i++) {
                if (*arr[i] < *arr[right]) {
                    tmp = arr[i];
                    arr[i] = arr[newPivotPosition];
                    arr[newPivotPosition] = tmp;
                    newPivotPosition++;
                }
            }
            pivotValue = arr[right];
            arr[right] = arr[newPivotPosition];
            arr[newPivotPosition] = pivotValue;
            return newPivotPosition;
        }
};

int main () {
    QuickSort sort;
    int  var[] = {8, 7, 9, 6, 10};
    int i, *ptr[5];
    for ( i = 0; i < 5; i++) {
        ptr[i] = &var[i]; 
    }
    cout << "\n";
    for (i = 0; i < 5; i++) {
        cout << *ptr[i];
    }
    cout << "\n";
    sort.sortPointers(ptr, 5);
    for (i = 0; i < 5; i++) {
        cout << *ptr[i];
    }
}