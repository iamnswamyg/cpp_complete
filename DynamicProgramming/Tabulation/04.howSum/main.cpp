//Combinotoric DP
#include <iostream>
#include <vector>

std::vector<int> howSum(int targetSum, const std::vector<int>& numbers) {
    std::vector<std::vector<int>*> table(targetSum + 1, nullptr);
    table[0] = new std::vector<int>();

    for (int x = 0; x <= targetSum; x++) {
        if (table[x] != nullptr) {
            for (const int& num : numbers) {
                int row = x + num;
                if (row <= targetSum) {
                    table[row] = new std::vector<int>(*table[x]);
                    table[row]->push_back(num);
                }
            }
        }
    }

    // Convert the result to a vector or return nullptr if no combination is found
    if (table[targetSum] != nullptr) {
        std::vector<int> result = *table[targetSum];
        for (int i = 0; i <= targetSum; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
        return result;
    } else {
        for (int i = 0; i <= targetSum; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
        return std::vector<int>();  // Return an empty vector for no combination
    }
}

int main() {
    std::vector<int> result1 = howSum(7, {2, 3});
    std::vector<int> result2 = howSum(7, {5, 3, 4, 7});
    std::vector<int> result3 = howSum(7, {2, 4});
    std::vector<int> result4 = howSum(13, {7, 1});
    std::vector<int> result5 = howSum(100, {25});
    std::vector<int> result6 = howSum(300, {7, 14});

    // Output the results
    for (const int& num : result1) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    for (const int& num : result2) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    for (const int& num : result3) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    for (const int& num : result4) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    for (const int& num : result5) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    for (const int& num : result6) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}
