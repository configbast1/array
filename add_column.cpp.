#include <iostream>
#include <windows.h>
using namespace std;

const int MAX = 10;

void addColumn(int matrix[MAX][MAX], int& cols, int rows, int pos, int newCol[MAX]) {
    if (pos < 0 || pos > cols) {
        cout << "Некорректная позиция.\n";
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = cols; j > pos; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][pos] = newCol[i];
    }

    cols++;
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    cout << "Результирующая матрица:\n";
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

    int matrix[MAX][MAX], newCol[MAX];
    int rows, cols, pos;

    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    cout << "Введите позицию для вставки столбца (от 0 до " << cols << "): ";
    cin >> pos;

    cout << "Введите значения нового столбца:\n";
    for (int i = 0; i < rows; i++)
        cin >> newCol[i];

    addColumn(matrix, cols, rows, pos, newCol);
    printMatrix(matrix, rows, cols);

    return 0;
}
