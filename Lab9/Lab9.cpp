#include <iostream>
#include "Lab9.h"

using namespace std;


void sort_arr() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 5, 2, 7, 10, -2, -5 };
    for (int i : arr)
        cout << i << ' ';
    cout << endl;

    sort(arr, sizeof(arr) / sizeof(int));

    for (int i : arr)
        cout << i << ' ';
    cout << endl;

    double arr_double[] = { 3.4, 2.1, 1.2, -8.9, 5.3 };

    for (double i : arr_double)
        cout << i << ' ';
    cout << endl;

    sort(arr_double, sizeof(arr_double) / sizeof(double));

    for (double i : arr_double)
        cout << i << ' ';
    cout << endl;
}

void max() {
    int i1 = 3, i2 = 5;
    int arr[] = { 8, 3, 5, 8 };
    cout << "max int = " << getmax(i1, i2) << endl;
    cout << "max int = " << getmax(arr, sizeof(arr) / sizeof(int)) << endl;
}

void max_str() {
    const char* s1 = "строка1";
    const char* s2 = "строка2";
    cout << "max str = " << getmax(s1, s2) << endl;
}

void train_sort() {
    int train[] = { 6, 3, 1 };
    Tstack<int> stack;
    for (int i : train) {
        stack.push(i);
    }

    for (int i = 0; i < sizeof(train) / sizeof(int); i++) {
        cout << stack.pop() << ' ';
    }
    cout << endl;
}

int main() {
    sort_arr();
    max();
    max_str();
    train_sort();

    return 0;
}