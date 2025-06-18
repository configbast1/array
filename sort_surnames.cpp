#include <iostream>
#include <windows.h>
using namespace std;

const int COUNT = 5;
const int LEN = 50;

bool compare(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
        i++;
    }
    return a[i] == '\0';
}

void copy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void sort(char arr[COUNT][LEN]) {
    char temp[LEN];
    for (int i = 0; i < COUNT - 1; i++) {
        for (int j = 0; j < COUNT - i - 1; j++) {
            if (!compare(arr[j], arr[j + 1])) {
                copy(temp, arr[j]);
                copy(arr[j], arr[j + 1]);
                copy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char surnames[COUNT][LEN];

    cout << "Введите 5 фамилий студентов:\n";
    for (int i = 0; i < COUNT; i++) {
        cout << i + 1 << ": ";
        cin.getline(surnames[i], LEN);
    }

    sort(surnames);

    cout << "\nОтсортированные фамилии:\n";
    for (int i = 0; i < COUNT; i++) {
        cout << surnames[i] << endl;
    }

    return 0;
}
