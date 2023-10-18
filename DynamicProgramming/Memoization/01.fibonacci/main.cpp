#include <iostream>
#include <unordered_map>

std::unordered_map<int, long long> memo;

long long fib(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    if (n <= 2) {
        return 1;
    }

    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main() {
    int n = 50; // Change 'n' to the desired Fibonacci number you want to calculate
    long long result = fib(n);
    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;

    return 0;
}
