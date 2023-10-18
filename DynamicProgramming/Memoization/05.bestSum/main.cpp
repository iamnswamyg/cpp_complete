#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, std::vector<int>> memo;

std::vector<int> bestSum(int targetSum, const std::vector<int>& numbers) {
    if (memo.find(targetSum) != memo.end()) {
        return memo[targetSum];
    }
    if (targetSum == 0) {
        return {};
    }
    if (targetSum < 0) {
        return { -1 }; // Use a marker value to indicate failure
    }

    std::vector<int> shortestCombination;

    for (int num : numbers) {
        int remainder = targetSum - num;
        std::vector<int> remainderCombination = bestSum(remainder, numbers);

        if ((!remainderCombination.empty() && remainderCombination[0] != -1)||(remainderCombination.empty())) {
            std::vector<int> combination = remainderCombination;
            combination.push_back(num);

            if (shortestCombination.empty() || combination.size() < shortestCombination.size()) {
                shortestCombination = combination;
            }
        }
    }

    
    memo[targetSum] = shortestCombination.empty() ? std::vector<int>{ -1 } : shortestCombination;
    return memo[targetSum];
}

int main() {
    std::vector<int> result;

   /*
    result = bestSum(8, {2, 3, 5});
    if (!result.empty() && result[0] != -1) {
        std::cout << "bestSum(8, {2, 3, 5}) = [";
        for (size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];
            if (i < result.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    } else {
        std::cout << "bestSum(8, {2, 3, 5}) = null" << std::endl;
    }*/


    result = bestSum(100, {1, 2, 5, 25});
    if (!result.empty() && result[0] != -1) {
        std::cout << "bestSum(100, {1, 2, 5, 25}) = [";
        for (size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];
            if (i < result.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    } else {
        std::cout << "bestSum(100, {1, 2, 5, 25}) = null" << std::endl;
    }
   

    return 0;
}
