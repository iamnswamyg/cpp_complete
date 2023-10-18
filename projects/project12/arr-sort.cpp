#include <iostream>

void sort(int array[], int size);

int main()
{
	int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
	int size = sizeof(array)/sizeof(array[0]);

	sort(array, size);

	for(int element : array){
		std::cout << element << " ";
	}

    return 0;
}
void sort(int array[], int size){
	int temp;
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

/*
{10, 1, 9, 2, 8, 3, 7, 4, 6, 5}

step1: i=0
1,10,9, 2, 8, 3, 7, 4, 6, 5
1,9,10, 2, 8, 3, 7, 4, 6, 5
1,9,2, 10, 8, 3, 7, 4, 6, 5
1,9,2, 8, 10, 3, 7, 4, 6, 5
1,9,2, 8, 3, 10, 7, 4, 6, 5
1,9,2, 8, 3, 7, 10, 4, 6, 5
1,9,2, 8, 3, 7, 4, 10, 6, 5
1,9,2, 8, 3, 7, 4, 6, 10, 5
1,9,2, 8, 3, 7, 4, 6, 5, 10

step2: i=1
1,9,2, 8, 3, 7, 4, 6, 5, 10
1,9,2, 8, 3, 7, 4, 6, 5, 10
1,2,9, 8, 3, 7, 4, 6, 5, 10
1,2,8, 9, 3, 7, 4, 6, 5, 10
1,2,8, 3, 9, 7, 4, 6, 5, 10
1,2,8, 3, 7, 9, 4, 6, 5, 10
1,2,8, 3, 7, 4, 9, 6, 5, 10
1,2,8, 3, 7, 4, 6, 9, 5, 10
1,2,8, 3, 7, 4, 6, 5, 9, 10

step3: i=2
1,2,8, 3, 7, 4, 6, 5, 9, 10
1,2,8, 3, 7, 4, 6, 5, 9, 10
1,2,3, 8, 7, 4, 6, 5, 9, 10
1,2,3, 7, 8, 4, 6, 5, 9, 10
1,2,3, 7, 4, 8, 6, 5, 9, 10
1,2,3, 7, 4, 6, 8, 5, 9, 10
1,2,3, 7, 4, 6, 5, 8, 9, 10

step4: i=3
1,2,3, 7, 4, 6, 5, 8, 9, 10
1,2,3, 7, 4, 6, 5, 8, 9, 10
1,2,3, 7, 4, 6, 5, 8, 9, 10
1,2,3, 4, 7, 6, 5, 8, 9, 10
1,2,3, 4, 6, 7, 5, 8, 9, 10
1,2,3, 4, 6, 5, 7, 8, 9, 10

step5: i=4
1,2,3, 4, 6, 5, 7, 8, 9, 10
1,2,3, 4, 6, 5, 7, 8, 9, 10
1,2,3, 4, 6, 5, 7, 8, 9, 10
1,2,3, 4, 6, 5, 7, 8, 9, 10
1,2,3, 4, 5, 6, 7, 8, 9, 10
*/