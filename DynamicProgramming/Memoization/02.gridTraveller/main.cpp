#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, long long> memo;

long long gridTraveler(int rows, int columns) {
    std::string key = std::to_string(rows) + "," + std::to_string(columns);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    if (rows == 0 || columns == 0) {
        return 0;
    }
    if (rows == 1 && columns == 1) {
        return 1;
    }

    memo[key] = gridTraveler(rows - 1, columns) + gridTraveler(rows, columns - 1);
    return memo[key];
}

int main() {
    int rows = 2;
    int columns = 3;
    std::cout << "gridTraveler(" << rows << "," << columns << ") = " << gridTraveler(rows, columns) << std::endl;

    rows = 18;
    columns = 18;
    std::cout << "gridTraveler(" << rows << "," << columns << ") = " << gridTraveler(rows, columns) << std::endl;

    return 0;
}
