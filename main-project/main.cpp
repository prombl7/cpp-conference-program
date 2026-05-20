#include <iostream>
#include <cstring>
#include "file_reader.h"

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
    cout << "Группа: 25 исит1д" << endl;  
    Report reports[MAX_SIZE];
    int n = readReports(reports, "data.txt");
    cout << "Загружено докладов: " << n << endl;

    for (int i = 0; i < n; i++)
        printReport(reports[i]);

    return 0;
}