#include <iostream>
#include <vector>

long long gridTraveler(int rows, int columns) {
    std::vector<std::vector<long long>> table(rows + 1, std::vector<long long>(columns + 1, 0));
    table[1][1] = 1;

    for (int m = 0; m <= rows; m++) {
        for (int n = 0; n <= columns; n++) {
            if (n < columns) {
                table[m][n + 1] += table[m][n];
            }
            if (m < rows) {
                table[m + 1][n] += table[m][n];
            }
        }
    }

    return table[rows][columns];
}

int main() {
    std::cout << gridTraveler(1, 1) << std::endl; // 1
    std::cout << gridTraveler(2, 3) << std::endl; // 3
    std::cout << gridTraveler(3, 2) << std::endl; // 3
    std::cout << gridTraveler(3, 3) << std::endl; // 6
    std::cout << gridTraveler(18, 18) << std::endl; // 2333606220
    return 0;
}
