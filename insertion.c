#include <stdio.h>
#include <math.h>

void insertionSort(int arr[], int n) {
	int i, j, key;
	for (i = 1; i < n; i+=1) {
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

void print(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
		printf("\n");
	}
}

int main() {
	int arr[] = {12, 9 , 13, 8, 17, 7, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	insertionSort(arr, n);
	print(arr, n);

	return 0;
}
