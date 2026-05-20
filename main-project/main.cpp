#include <iostream>
#include <cstring>
#include "file_reader.h"
#include "filter.h"

using namespace std;

void printReport(const Report& r) {
    printf("%02d:%02d-%02d:%02d %s %s %s \"%s\"\n",
        r.startHour, r.startMin,
        r.endHour, r.endMin,
        r.lastName, r.firstName, r.middleName,
        r.topic);
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Вариант 2. Программа конференции" << endl;
    cout << "Автор: Бурунов Иван" << endl;
    cout << "Группа: 25исит1д" << endl;

    Report reports[MAX_SIZE];
    int n = readReports(reports, "data.txt");

    Report* ptrs[MAX_SIZE];
    for (int i = 0; i < n; i++) ptrs[i] = &reports[i];

    Report* filtered[MAX_SIZE];

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Доклады Иванова Ивана Ивановича" << endl;
        cout << "2. Доклады длительностью больше 15 минут" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        int k = 0;
        if (choice == 1) {
            k = filterByAuthor(ptrs, n, filtered,
                "Иванов", "Иван", "Иванович");
            cout << "Найдено: " << k << endl;
            for (int i = 0; i < k; i++) printReport(*filtered[i]);
        }
        else if (choice == 2) {
            k = filterByDuration(ptrs, n, filtered, 15);
            cout << "Найдено: " << k << endl;
            for (int i = 0; i < k; i++) printReport(*filtered[i]);
        }
    } while (choice != 0);

    return 0;
}