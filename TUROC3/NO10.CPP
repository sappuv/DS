//Implement Heap sort to sort given set of values using max or min heap cpp

//MAX

#include <iostream.h>
#include <conio.h>


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int *arr, int index, int size) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest]) {
	largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
	largest = right;
    }

    if (largest != index) {
	swap(arr[index], arr[largest]);
	heapify(arr, largest, size);
    }
}

void heapSort(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
	heapify(arr, i, size);
    }

    for (int j = size - 1; j >= 0; j--) {
	swap(arr[0], arr[j]);

	heapify(arr, 0, j);
    }
}
int main() {
    clrscr();

    int arr[] = {3, 5, 1, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);
    for (int i = 0; i < size; i++) {
	cout << arr[i] << " ";
    }
    cout << endl;
    getch();
    return 0;
}



/* MIN

if (left < size && arr[left] < arr[largest]) {
    largest = left;
}
if (right < size && arr[right] < arr[largest]) {
    largest = right;
}

*/