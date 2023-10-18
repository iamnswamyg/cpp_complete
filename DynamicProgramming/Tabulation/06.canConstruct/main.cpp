#include <iostream>
#include <vector>
#include <string>

bool canConstruct(const std::string& target, const std::vector<std::string>& wordBank) {
    std::vector<bool> table(target.length() + 1, false);
    table[0] = true;

    for (size_t i = 0; i <= target.length(); i++) {
        if (!table[i]) continue;

        for (const std::string& word : wordBank) {
            if (i + word.length() <= target.length() &&
                target.substr(i, word.length()) == word) {
                table[i + word.length()] = true;
            }
        }
    }

    return table[target.length()];
}

int main() {
    std::cout << std::boolalpha;  // Print boolean values as true/false
    std::cout << canConstruct("banana", {"ba", "pa", "ca", "na"}) << std::endl;  // true
    std::cout << canConstruct("", {"ba", "pa", "ca", "na"}) << std::endl;         // true
    std::cout << canConstruct("abcdef", {"ab", "abcdefgh", "c", "def"}) << std::endl;  // true
    std::cout << canConstruct("potato", {"pot", "ta", "to"}) << std::endl;         // false
    std::cout << canConstruct("skateboard", {"skat", "te", "bor", "ard"}) << std::endl;  // false
    std::cout << canConstruct("skateboard", {"skat", "te", "e", "bo", "ard"}) << std::endl;  // true

    return 0;
}
