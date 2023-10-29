#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 두 행렬을 더하는 함수
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix1(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> matrix2(rows, std::vector<int>(cols));

    // 랜덤 데이터로 초기화
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = std::rand() % 100;
            matrix2[i][j] = std::rand() % 100;
        }
    }

    std::vector<std::vector<int>> result = addMatrices(matrix1, matrix2);

    // 결과 출력
    std::cout << "Matrix 1:\n";
    for (const auto& row : matrix1) {
        for (int val : row) {
            std::cout << val << '\t';
        }
        std::cout << '\n';
    }

    std::cout << "Matrix 2:\n";
    for (const auto& row : matrix2) {
        for (int val : row) {
            std::cout << val << '\t';
        }
        std::cout << '\n';
    }

    std::cout << "Result Matrix:\n";
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}
