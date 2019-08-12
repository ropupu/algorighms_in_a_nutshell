// INSERTION SORT SUMMARY
// Best: O(n)    Average, Worst: O(n2)
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class InsertionSort {
    public:
        void sort(int arr[], int size) {
            for (int i = 1; i < size; i++) {
                insert(arr, i, arr[i]);
            }
        }
        void sortPointers(int *arr[], int size) {
            for (int i = 1; i < size; i++) {
                int* value = arr[i];
                int position = i - 1;
                while (position >= 0 && *arr[position] > *value) {
                    arr[position+1] = arr[position];
                    position--;
                }
                arr[position+1] = value;
            }
        }
        void sortValues(int arr[], int size) {
            int memSize = sizeof(int);
            void *buffer = malloc(memSize);
            for (int i = 1; i < size; i++) {
                int position = i - 1;
                void *value = (arr + i);
                while (position >= 0 && arr[position] > *(int*)value) {
                    position--;
                }
                if (++position == i) continue;
                memmove (buffer, value, memSize);
                memmove (arr + position + 1, arr + position, memSize*(i - position));
                memmove (arr + position, buffer, memSize);
            }
            free(buffer);
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
    int var2[] = {4, 5, 2, 3, 1};
    cout << "\n";
    for (i = 0; i < 5; i++) {
        cout << var2[i];
    }
    cout << "\n";
    sort.sortValues(var2, 5);
    for (i = 0; i < 5; i++) {
        cout << var2[i];
    }

    return 0;
}