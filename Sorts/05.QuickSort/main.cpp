#include<iostream>
using namespace std;


 int partition(int array[], int start, int end) {
		
		int pivot = array[end];
		int i = start - 1;
		
		for(int j = start; j <= end; j++) {
			if(array[j] < pivot) {
				i++;
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		i++;
		int temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		
		return i;
	}

void quickSort(int array[], int start, int end) {
		
		if(end <= start) return; //base case
		
		int pivot = partition(array, start, end);
		quickSort(array, start, pivot - 1);
		quickSort(array, pivot + 1, end);		
	}

void displayArray(int arr[], int n) {
    cout << "The array elements are - ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {

    int n;
    cout << "Enter the size of the array - ";
    cin >> n;

    int arr[n];
    cout << "Enter the " << n << " array elements - ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "\nBefore sorting\n";
    displayArray(arr, n);

    quickSort(arr, 0,n-1);

    cout << "\nAfter sorting\n";
    displayArray(arr, n);

    return 0;
}

/*
 * Time Complexity  : O(nlogn)
 * Auxiliary Space  : O(nlogn)
*/

