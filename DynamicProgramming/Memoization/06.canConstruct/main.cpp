#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, bool> memo;

bool canConstruct(const std::string& target, const std::vector<std::string>& wordBank) {
    if (memo.find(target) != memo.end()) {
        return memo[target];
    }
    if (target.empty()) {
        return true;
    }

    for (const std::string& word : wordBank) {
        if (target.find(word) == 0) {
            std::string suffix = target.substr(word.length());
            if (canConstruct(suffix, wordBank)) {
                memo[target] = true;
                return true;
            }
        }
    }

    memo[target] = false;
    return false;
}

int main() {
    std::cout << std::boolalpha; // Print true/false instead of 1/0

  //  std::cout << canConstruct("skateboard", { "skat", "te", "e", "bo", "ard" }) << std::endl; // True
    std::cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {
        "e", "ee", "eee", "eeee", "eeeee", "eeeeee", "eeeeeee", "eeeeeeee"
    }) << std::endl; // False
    

    return 0;
}
