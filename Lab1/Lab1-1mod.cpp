#include <iostream>
using namespace std;

void main(void)
{
	setlocale(LC_ALL, "Russian");
	int i, k, number;
	int power(int, int);
	cout << "¬ведите число: ";
	cin >> number;
	for (i = 0; i < 10; i++)
	{
		k = power(number, i);
		cout << "i = " << i << ", k = " << k << endl;
	}
}

int power(int x, int n)
{
	int i, p = 1;
	for (i = 0; i < n; i++) p *= x;
	return p;
}
