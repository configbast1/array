#include <iostream>
#include <windows.h>
using namespace std;

const int MAX = 10;

void transpose(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transposed[j][i] = matrix[i][j];
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

    int matrix[MAX][MAX], transposed[MAX][MAX];
    int rows, cols;

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    transpose(matrix, transposed, rows, cols);

    cout << "Транспонированная матрица:\n";
    printMatrix(transposed, cols, rows);

    return 0;
}
