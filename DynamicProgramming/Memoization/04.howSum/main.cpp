//works by combinotrics
#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, std::vector<int>> memo;

std::vector<int> howSum(int targetSum, const std::vector<int>& numbers) {
    if (memo.find(targetSum) != memo.end()) {
        return memo[targetSum];
    }
    if (targetSum == 0) {
        return {};
    }
    if (targetSum < 0) {
        return { -1 }; // Use a marker value to indicate failure
    }

    for (int num : numbers) {
        int remainder = targetSum - num;
        std::vector<int> remainderResult = howSum(remainder, numbers);

        if ((!remainderResult.empty() && remainderResult[0] != -1) ||(remainderResult.empty())) {
            remainderResult.push_back(num);
            memo[targetSum] = remainderResult;
            return remainderResult;
        } else{
            memo[remainder] = { -1 }; // Use a marker value to indicate failure
        }
    }

    memo[targetSum] = { -1 }; // Use a marker value to indicate failure
    return { -1 }; // Use a marker value to indicate failure
}

int main() {
    std::vector<int> result;

    result = howSum(8, {2, 3, 5});
    if (!result.empty() && result[0] != -1) {
        std::cout << "howSum(8, {2, 3, 5}) = [";
        for (size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];
            if (i < result.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    } else {
        std::cout << "howSum(8, {2, 3, 5}) = null" << std::endl;
    }
/*
   result = howSum(300, {7, 14});
    if (!result.empty() && result[0] != -1) {
        std::cout << "howSum(300, {7, 14,}) = [";
        for (size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];
            if (i < result.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    } else {
        std::cout << "howSum(300, {7, 14}) = null" << std::endl;
    }*/

    return 0;
}
