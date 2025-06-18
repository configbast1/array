#include <iostream>
#include <windows.h>
using namespace std;

const int MAX = 10;
const int MAXV = MAX * MAX * 3;

bool exists(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) if (arr[i] == val) return true;
    return false;
}

void inputMatrix(int mat[MAX][MAX], int& r, int& c, char name) {
    cout << "Размеры матрицы " << name << ": "; cin >> r >> c;
    cout << "Введите матрицу " << name << ":\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> mat[i][j];
}

bool inMatrix(int val, int m[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (m[i][j] == val) return true;
    return false;
}

void collectCommon(int a[MAX][MAX], int ra, int ca,
                   int b[MAX][MAX], int rb, int cb,
                   int c[MAX][MAX], int rc, int cc,
                   int res[], int& cnt) {
    for (int i = 0; i < ra; i++)
        for (int j = 0; j < ca; j++) {
            int val = a[i][j];
            if (inMatrix(val, b, rb, cb) && inMatrix(val, c, rc, cc) && !exists(res, cnt, val))
                res[cnt++] = val;
        }
}

void collectUnique(int base[MAX][MAX], int rb, int cb,
                   int m1[MAX][MAX], int r1, int c1,
                   int m2[MAX][MAX], int r2, int c2,
                   int res[], int& cnt) {
    for (int i = 0; i < rb; i++)
        for (int j = 0; j < cb; j++) {
            int val = base[i][j];
            if (!inMatrix(val, m1, r1, c1) && !inMatrix(val, m2, r2, c2) && !exists(res, cnt, val))
                res[cnt++] = val;
        }
}

void collectCommonAC(int a[MAX][MAX], int ra, int ca,
                     int c[MAX][MAX], int rc, int cc,
                     int res[], int& cnt) {
    for (int i = 0; i < ra; i++)
        for (int j = 0; j < ca; j++) {
            int val = a[i][j];
            if (inMatrix(val, c, rc, cc) && !exists(res, cnt, val))
                res[cnt++] = val;
        }
}

void print(const char* label, int arr[], int count) {
    cout << label << ": ";
    for (int i = 0; i < count; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1, c1, r2, c2, r3, c3;

    inputMatrix(A, r1, c1, 'A');
    inputMatrix(B, r2, c2, 'B');
    inputMatrix(C, r3, c3, 'C');

    int commonABC[MAXV], countABC = 0;
    int unique[MAXV], countU = 0;
    int commonAC[MAXV], countAC = 0;

    collectCommon(A, r1, c1, B, r2, c2, C, r3, c3, commonABC, countABC);
    collectUnique(A, r1, c1, B, r2, c2, C, r3, c3, unique, countU);
    collectUnique(B, r2, c2, A, r1, c1, C, r3, c3, unique, countU);
    collectUnique(C, r3, c3, A, r1, c1, B, r2, c2, unique, countU);
    collectCommonAC(A, r1, c1, C, r3, c3, commonAC, countAC);

    cout << "\nРезультаты:\n";
    print("Общие значения A, B, C", commonABC, countABC);
    print("Уникальные значения", unique, countU);
    print("Общие значения A и C", commonAC, countAC);

    return 0;
}
