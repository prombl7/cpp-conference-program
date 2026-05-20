#include <iostream>
#include <cstring>
#include "file_reader.h"
#include "filter.h"
#include "sort.h"

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
        cout << "3. Сортировка" << endl;
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
        else if (choice == 3) {
            SortFunc sortFuncs[] = { heapSort, mergeSort };
            CompareFunc cmpFuncs[] = { compareByDurationDesc, compareByAuthorTopic };

            cout << "Метод сортировки:" << endl;
            cout << "1. Пирамидальная (Heap sort)" << endl;
            cout << "2. Слиянием (Merge sort)" << endl;
            int sm; cin >> sm;

            cout << "Критерий:" << endl;
            cout << "1. По убыванию длительности" << endl;
            cout << "2. По возрастанию фамилии и темы" << endl;
            int sc; cin >> sc;

        
            Report* tmp[MAX_SIZE];
            for (int i = 0; i < n; i++) tmp[i] = ptrs[i];

            sortFuncs[sm - 1](tmp, n, cmpFuncs[sc - 1]);

            for (int i = 0; i < n; i++) printReport(*tmp[i]);
        }
    } while (choice != 0);

    return 0;
}