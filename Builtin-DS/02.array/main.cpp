#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
 
int main()
{
    // Construction uses aggregate initialization
    std::array<int, 3> a1{{1, 2, 3}}; // Double-braces required in C++11 prior to
                                      // the CWG 1270 revision (not needed in C++11
                                      // after the revision and in C++14 and beyond)
 
    std::array<int, 3> a2 = {1, 2, 3}; // Double braces never required after =
 
    // Container operations are supported
    std::sort(a1.begin(), a1.end());
    std::ranges::reverse_copy(a2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    // Ranged for loop is supported
    std::array<std::string, 2> a3{"E", "\u018E"};
    for (const auto& s : a3)
        std::cout << s << ' ';
    std::cout << '\n';
}