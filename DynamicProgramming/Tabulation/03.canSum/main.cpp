//Decision DP

#include <iostream>
#include <vector>

bool canSum(int targetSum, const std::vector<int>& numbers) {
    std::vector<bool> table(targetSum + 1, false);
    table[0] = true;

    for (int x = 0; x <= targetSum; x++) {
        if (!table[x]) continue;

        for (const int& num : numbers) {
            int row = x + num;
            if (row <= targetSum) {
                table[row] = true;
            }
        }
    }

    return table[targetSum];
}

int main() {
    std::cout << std::boolalpha;  // Print boolean values as true/false
    std::cout << canSum(7, {2, 3}) << std::endl;           // true
    std::cout << canSum(7, {5, 3, 4, 7}) << std::endl;     // true
    std::cout << canSum(7, {2, 4}) << std::endl;           // false
    std::cout << canSum(7, {2, 3, 5}) << std::endl;        // true
    std::cout << canSum(7, {2, 3, 5, 7}) << std::endl;     // true
    std::cout << canSum(197, {1, 10, 2}) << std::endl;     // true
    std::cout << canSum(300, {7, 14}) << std::endl;        // false
    std::cout << canSum(3042970, {240022, 100000, 1}) << std::endl;  // true

    return 0;
}
