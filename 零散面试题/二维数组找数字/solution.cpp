#include <iostream>
#include <vector>

using namespace std;

// 查找二维数组中是否存在目标值m，存在返回true，否则返回false
bool findNumberIn2DArray(vector<vector<int>>& matrix, int m) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0;
    int col = cols - 1;
    while (row < rows && col >= 0) {
        if (matrix[row][col] == m) {
            return true;
        } else if (matrix[row][col] < m) {
            row++;
        } else {
            col--;
        }
    }
    return false;
}

int main() {
    // 定义题目中的二维数组
    vector<vector<int>> matrix = {
        {3, 8, 10, 13},
        {15, 17, 22, 25},
        {23, 26, 29, 31},
        {27, 30, 33, 34}
    };
    int m = 27;
    if (findNumberIn2DArray(matrix, m)) {
        cout << "找到数字 " << m << endl;
    } else {
        cout << "未找到数字 " << m << endl;
    }
    return 0;
}