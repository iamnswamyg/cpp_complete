//Optimization DP

#include <iostream>
#include <vector>

std::vector<int> bestSum(int targetSum, const std::vector<int>& numbers) {
    std::vector<std::vector<int>*> table(targetSum + 1, nullptr);
    table[0] = new std::vector<int>();

    for (int i = 0; i <= targetSum; i++) {
        if (table[i] != nullptr) {
            for (const int& num : numbers) {
                std::vector<int> combination = *(table[i]);
                combination.push_back(num);

                int row = i + num;
                if (row<=targetSum && (table[row] == nullptr || combination.size() < table[row]->size())) {
                    if (table[row] != nullptr) {
                        delete table[row];
                    }
                    table[row] = new std::vector<int>(combination);
                }
            }
        }
    }

    // Convert the result to a vector or return nullptr if no combination is found
    if (table[targetSum] != nullptr) {
        std::vector<int> result = *(table[targetSum]);
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
    std::vector<int> result1 = bestSum(7, {5, 3, 4, 7});
    std::vector<int> result2 = bestSum(8, {2, 3, 5});
    std::vector<int> result3 = bestSum(8, {1, 4, 5});
    std::vector<int> result4 = bestSum(100, {1, 2, 5, 25});

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

    return 0;
}
