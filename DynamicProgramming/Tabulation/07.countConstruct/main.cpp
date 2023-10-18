#include <iostream>
#include <vector>
#include <string>

int countConstruct(const std::string& target, const std::vector<std::string>& wordBank) {
    std::vector<int> table(target.length() + 1, 0);
    table[0] = 1;

    for (size_t i = 0; i <= target.length(); i++) {
        if (table[i] == 0) continue;

        for (const std::string& word : wordBank) {
            if (i + word.length() <= target.length() &&
                target.substr(i, word.length()) == word) {
                table[i + word.length()] += table[i];
            }
        }
    }

    return table[target.length()];
}

int main() {
    std::cout << countConstruct("banana", {"ba", "pa", "ca", "na"}) << std::endl;  // 1
    std::cout << countConstruct("purple",{"purp","p","ur","le","purpl"}) << std::endl;         // 2
    std::cout << countConstruct("abcdef", {"ab", "abcdefgh", "c", "def"}) << std::endl;  // 1
    std::cout << countConstruct("potato", {"pot", "ta", "to"}) << std::endl;//0
    return 0;
}
