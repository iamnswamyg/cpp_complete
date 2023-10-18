#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, bool> memo;

bool canSum(int targetSum, const std::vector<int>& numbers) {
    if (memo.find(targetSum) != memo.end()) {
        return memo[targetSum];
    }
    if (targetSum == 0) {
        return true;
    }
    if (targetSum < 0) {
        return false;
    }

    for (int num : numbers) {
        int remainder = targetSum - num;
        if (canSum(remainder, numbers)) {
            memo[targetSum] = true;
            return true;
        }
    }

    memo[targetSum] = false;
    return false;
}

int main() {
    std::cout << std::boolalpha; // Print true/false instead of 1/0

    /*std::cout << canSum(7, {2, 3}) << std::endl; // true
    std::cout << canSum(7, {5, 3, 4, 7}) << std::endl; // true
    std::cout << canSum(7, {2, 4}) << std::endl; // false
    std::cout << canSum(7, {2, 3, 5}) << std::endl; // true
    std::cout << canSum(7, {2, 3, 5, 7}) << std::endl; // true
    std::cout << canSum(197, {1, 10, 2}) << std::endl; // true
    std::cout << canSum(300, {7, 14}) << std::endl; // false
    */
    std::cout << canSum(3042970, {240022, 100000, 1}) << std::endl; // true
    

    return 0;
}
