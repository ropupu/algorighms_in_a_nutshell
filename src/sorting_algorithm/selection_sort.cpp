// O(n2)
#include <iostream>
using namespace std;

class SelectionSort {
    public:
        void sortPointers(int *arr[], int size) {
            for (int maxPos = size - 1; maxPos > 0; maxPos--) {
                int position = 0;
                int* max = arr[position];
                for (int i = 0; i <= maxPos; i++) {
                    if (*max < *arr[i]) {
                        position = i;
                        max = arr[i];
                    }
                }
                arr[position] = arr[maxPos];
                arr[maxPos] = max;
            }
        }
};

int main () {
    SelectionSort sort;
    int  var[] = {8, 7, 9, 6, 10};
    int i, *ptr[5];
 
    for ( i = 0; i < 5; i++) {
        ptr[i] = &var[i]; 
    }
    for (i = 0; i < 5; i++) {
        cout << *ptr[i];
    }
    sort.sortPointers(ptr, 5);
    cout << "\n";
    for (i = 0; i < 5; i++) {
        cout << *ptr[i];
    }
}
