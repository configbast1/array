#include <iostream>
#include <windows.h>
using namespace std;

const int MAX = 10;

void shiftRight(int matrix[MAX][MAX], int rows, int cols, int k) {
    for (int r = 0; r < rows; r++) {
        for (int step = 0; step < k; step++) {
            int last = matrix[r][cols - 1];
            for (int j = cols - 1; j > 0; j--) {
                matrix[r][j] = matrix[r][j - 1];
            }
            matrix[r][0] = last;
        }
    }
}

void shiftLeft(int matrix[MAX][MAX], int rows, int cols, int k) {
    for (int r = 0; r < rows; r++) {
        for (int step = 0; step < k; step++) {
            int first = matrix[r][0];
            for (int j = 0; j < cols - 1; j++) {
                matrix[r][j] = matrix[r][j + 1];
            }
            matrix[r][cols - 1] = first;
        }
    }
}

void shiftDown(int matrix[MAX][MAX], int rows, int cols, int k) {
    for (int c = 0; c < cols; c++) {
        for (int step = 0; step < k; step++) {
            int last = matrix[rows - 1][c];
            for (int i = rows - 1; i > 0; i--) {
                matrix[i][c] = matrix[i - 1][c];
            }
            matrix[0][c] = last;
        }
    }
}

void shiftUp(int matrix[MAX][MAX], int rows, int cols, int k) {
    for (int c = 0; c < cols; c++) {
        for (int step = 0; step < k; step++) {
            int first = matrix[0][c];
            for (int i = 0; i < rows - 1; i++) {
                matrix[i][c] = matrix[i + 1][c];
            }
            matrix[rows - 1][c] = first;
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int matrix[MAX][MAX];
    int rows, cols, k;
    char direction;

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    cout << "Введите направление сдвига (r/l/u/d): ";
    cin >> direction;
    cout << "Введите количество сдвигов: ";
    cin >> k;

    if (direction == 'r') shiftRight(matrix, rows, cols, k);
    else if (direction == 'l') shiftLeft(matrix, rows, cols, k);
    else if (direction == 'd') shiftDown(matrix, rows, cols, k);
    else if (direction == 'u') shiftUp(matrix, rows, cols, k);
    else cout << "Некорректное направление\n";

    cout << "Результат:\n";
    printMatrix(matrix, rows, cols);

    return 0;
}
