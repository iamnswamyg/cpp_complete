#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Function to implement allConstruct
std::vector<std::vector<std::string>> allConstruct(const std::string &target, const std::vector<std::string> &wordBank) {
    std::vector<std::vector<std::vector<std::string>>> table(target.length() + 1);

    // Initialize table[0] with an empty vector
    table[0].push_back(std::vector<std::string>());

    for (int i = 0; i <= target.length(); ++i) {
        for (const std::string &word : wordBank) {
            if (i + word.length() <= target.length() && target.substr(i, word.length()) == word) {
                // Create new combinations
                for (const std::vector<std::string> &subarray : table[i]) {
                    std::vector<std::string> newCombination = subarray;
                    newCombination.push_back(word);
                    table[i + word.length()].push_back(newCombination);
                }
            }
        }
    }

    return table[target.length()];
}

void printResult(const std::vector<std::vector<std::string>>& result) {
    
    if(result.size()==0){
         std::cout << "[";
         std::cout << "]" << std::endl;
         return;
        }
     std::cout << "[" << std::endl;
    for (const std::vector<std::string>& combination : result) {
        std::cout << "[";
        for (size_t i = 0; i < combination.size(); i++) {
            std::cout << combination[i];
            if (i < combination.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]," << std::endl;
    }
    std::cout << "]" << std::endl;
    std::cout << "----------------" << std::endl;
}

int main() {
    // Test cases (unchanged)
    std::vector<std::vector<std::string>> result1 = allConstruct("purple", {"purp", "p", "ur", "le", "purpl"});
    std::vector<std::vector<std::string>> result2 = allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"});
    std::vector<std::vector<std::string>> result3 = allConstruct("potato", {"pot", "ta", "to"});

    // Display the results (unchanged)
    printResult(result1);
    printResult(result2);
    printResult(result3);

    return 0;
}
