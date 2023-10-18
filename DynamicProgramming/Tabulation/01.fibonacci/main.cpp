#include <iostream>
#include <vector>

long long fib(int n) {
    std::vector<long long> table(n + 1, 0);
    table[1] = 1;
    
    for (int i = 0; i <= n; i++) {
        if (i + 1 <= n) {
            table[i + 1] += table[i];
        }
        if (i + 2 <= n) {
            table[i + 2] += table[i];
        }
    }
    
    return table[n];
}

int main() {
    std::cout << fib(6) << std::endl; // 8
    std::cout << fib(7) << std::endl; // 13
    std::cout << fib(8) << std::endl; // 21
    std::cout << fib(50) << std::endl; // 12586269025
    return 0;
}
