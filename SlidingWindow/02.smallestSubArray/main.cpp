#include <iostream>
#include <vector>
#include <string>
#include<limits>

using namespace std;

int smallestSubarray(int targetSum, int arr[], int size) {
        
        int minWindowSize = std::numeric_limits<int>::max();
        int currentWindowSum = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < size; windowEnd++) {
            currentWindowSum += arr[windowEnd];

            while(currentWindowSum >= targetSum) {
                minWindowSize = min(minWindowSize, windowEnd - windowStart + 1);
                currentWindowSum -= arr[windowStart];
                windowStart++;
            }
        }

        return minWindowSize;
    }


int main()
{
    int arr[]{4,2,2,7,8,1,2,8,10};
    cout << size(arr) << endl;
    cout << smallestSubarray(8,arr,size(arr))<< endl;
}