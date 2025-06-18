#include <iostream>
#include <windows.h>
using namespace std;

const int MAX = 10;
const int LEN = 50;

bool equals(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

void copy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void display(char names[MAX][LEN], char phones[MAX][LEN], int count) {
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << names[i] << " — " << phones[i] << endl;
    }
}

void searchByName(char names[MAX][LEN], char phones[MAX][LEN], int count, const char* name) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (equals(names[i], name)) {
            cout << "Найден: " << names[i] << " — " << phones[i] << endl;
            found = true;
        }
    }
    if (!found) cout << "Имя не найдено.\n";
}

void searchByPhone(char names[MAX][LEN], char phones[MAX][LEN], int count, const char* phone) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (equals(phones[i], phone)) {
            cout << "Найден: " << names[i] << " — " << phones[i] << endl;
            found = true;
        }
    }
    if (!found) cout << "Телефон не найден.\n";
}

void editEntry(char names[MAX][LEN], char phones[MAX][LEN], int count, int index) {
    if (index < 0 || index >= count) {
        cout << "Неверный индекс.\n";
        return;
    }
    cout << "Введите новое имя: ";
    cin.getline(names[index], LEN);
    cout << "Введите новый телефон: ";
    cin.getline(phones[index], LEN);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char names[MAX][LEN];
    char phones[MAX][LEN];
    int count;

    cout << "Сколько записей вы хотите ввести? ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        cout << "Имя #" << i + 1 << ": ";
        cin.getline(names[i], LEN);
        cout << "Телефон #" << i + 1 << ": ";
        cin.getline(phones[i], LEN);
    }

    display(names, phones, count);

    char query[LEN];
    cout << "Поиск по имени: ";
    cin.getline(query, LEN);
    searchByName(names, phones, count, query);

    cout << "Поиск по телефону: ";
    cin.getline(query, LEN);
    searchByPhone(names, phones, count, query);

    int index;
    cout << "Введите номер записи для редактирования: ";
    cin >> index;
    cin.ignore();
    editEntry(names, phones, count, index - 1);

    display(names, phones, count);

    return 0;
}
