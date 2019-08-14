// O(nlogn)
#include <iostream>
using namespace std;

class HeapSort {
    public:
        void sortPointers(int* arr[], int size) {
            buildHeap(arr, size);
            for (int i = size - 1; i > 0; i--) {
                int* tmp = arr[i];
                arr[i] = arr[0];
                arr[0] = tmp;
                buildHeap(arr, i);
            }
        }
    private:
        void buildHeap(int* arr[], int size) {
            int rootIdx = (size + 1)/2 - 1;
            for (int i = rootIdx; i >= 0; i--) {
                heapify(arr, i, size);
            }
        }
        void heapify(int* arr[], int rootIdx, int size) {
            int largestIdx = rootIdx;
            int childLeft = rootIdx*2 + 1;
            int childRight = rootIdx*2 + 2;
            if (childLeft < size && *arr[childLeft] > *arr[largestIdx]) {
                largestIdx = childLeft;
            }
            if (childRight < size && *arr[childRight] > *arr[largestIdx]) {
                largestIdx = childRight;
            }
            if (largestIdx != rootIdx) {
                int* tmp = arr[rootIdx];
                arr[rootIdx] = arr[largestIdx];
                arr[largestIdx] = tmp;
                heapify(arr, largestIdx, size);
            }
        }
};

int main () {
    HeapSort sort;
    int  var[] = {8, 7, 9, 6, 10};
    for (int i = 0; i < 5; i++) {
        cout << var[i];
    }
    cout << endl;
    int *ptr[5];
    for (int i = 0; i < 5; i++) {
        ptr[i] = &var[i]; 
    }
    sort.sortPointers(ptr, 5);
    for (int i = 0; i < 5; i++) {
        cout << *ptr[i];
    }
}
