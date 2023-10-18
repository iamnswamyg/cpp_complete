#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, int> memo;

int countConstruct(const std::string& target, const std::vector<std::string>& wordBank) {
    if (memo.find(target) != memo.end()) {
        return memo[target];
    }
    if (target.empty()) {
        return 0;
    }

    int totalCount = 0;
    for (const std::string& word : wordBank) {
        if (target.find(word) == 0) {
            std::string suffix = target.substr(word.length());
            if (suffix.empty()) {
                totalCount++;
            } else {
                totalCount += countConstruct(suffix, wordBank);
            }
        }
    }

    memo[target] = totalCount;
    return totalCount;
}

int main() {
    std::cout << "countConstruct(\"purple\",{\"purp\",\"p\",\"ur\",\"le\",\"purpl\"}) = " << countConstruct("purple",{"purp","p","ur","le","purpl"}) << std::endl; 
   // std::cout << "countConstruct(\"skateboard\", {\"bo\", \"rd\", \"ate\", \"t\", \"ska\",\"sk\",\"boar\"}) = " << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska","sk","boar"}) << std::endl; // 1
   // std::cout << "countConstruct(\"eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef\", {\"e\", \"ee\", \"eee\", \"eeee\", \"eeeee\", \"eeeeee\", \"eeeeeee\", \"eeeeeeee\"}) = " << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee", "eeeeeee", "eeeeeeee"}) << std::endl; // 0

    return 0;
}
