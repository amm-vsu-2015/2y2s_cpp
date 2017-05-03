
/**

	Входные данные для проверки:
*/

#include <iostream>
#include <cmath>
using namespace std;



int main()
{

	setlocale(LC_ALL, "Russian");

	int const COUNT = 30;
	int x[COUNT], y[COUNT];

	cout << "Введите значения элементов первой последовательности х: ";

	for (int i = 0; i < COUNT - 1; i++) {
		cin >> x[i];
	}

	cout << "Введите значения элементов второй последовательности y: ";
	for (int i = 0; i < COUNT - 1; i++) {
		cin >> x[i];
	}

	int min = INT_MAX;
	int k = 0;

	for (int i = 0; i < COUNT - 1; i++) {
		k = 1;
		while ((k < COUNT) && (x[i] != y[i])) k++;

		if ((k >= COUNT) && (min > x[i])) {
			min = x[i];
		}
	}

	std::cout << '\n' << min << '\n';


	int stop;
	cin >> stop;
  return 0;
}
