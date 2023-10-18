#include <iostream>
#include <vector>
#include <string>
#include<limits>

using namespace std;

int findMaxSumSubarray(int arr[], int size,int k) {
        int maxValue = std::numeric_limits<int>::min();
        int currentRunningSum = 0;

        for (int i = 0; i < size; i++) {
            currentRunningSum += arr[i];

            if (i >= k - 1) {
                maxValue = max(maxValue, currentRunningSum);
                currentRunningSum -= arr[i - (k - 1)];
            }
        }

        return maxValue;
    }


int main()
{
    int arr[]{4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    cout << size(arr) << endl;
    cout << findMaxSumSubarray(arr,size(arr), 3)<< endl;
}