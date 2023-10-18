#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, std::vector<std::vector<std::string>>> memo;

std::vector<std::vector<std::string>> allConstruct(const std::string& target, const std::vector<std::string>& wordBank) {
    if (memo.find(target) != memo.end()) {
        return memo[target];
    }
    if (target.empty()) {
        return { {} }; // Return a vector with an empty vector to represent an empty combination
    }

    std::vector<std::vector<std::string>> result;
    for (const std::string& word : wordBank) {
        if (target.find(word) == 0) {
            std::string suffix = target.substr(word.length());
            std::vector<std::vector<std::string>> suffixWays = allConstruct(suffix, wordBank);
            for (const std::vector<std::string>& suffixWay : suffixWays) {
                std::vector<std::string> targetWay = { word };
                targetWay.insert(targetWay.end(), suffixWay.begin(), suffixWay.end());
                result.push_back(targetWay);
            }
        }
    }

    memo[target] = result;
    return result;
}

void printResult(const std::vector<std::vector<std::string>>& result) {
    if(result.size()==0){
         std::cout << "[";
         std::cout << "]" << std::endl;
        }
    for (const std::vector<std::string>& combination : result) {
        std::cout << "[";
        for (size_t i = 0; i < combination.size(); i++) {
            std::cout << combination[i];
            if (i < combination.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    std::vector<std::vector<std::string>> result;
    
    result=allConstruct("purple",{"purp","p","ur","le","purpl"});

    //result = allConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd", "ef", "c" });

    //result=allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee", "eeeeeee", "eeeeeeee"});
    printResult(result);

    return 0;
}
