
/**
	Ввести 3 числа. Если они могут быть длинами сторо равнобедренного остроугольного
	треугольника, вычислить его площадь. Вывести длины сторон и площадь в порядке
	возрастания.

	Входные данные для проверки:
	4 4 5
	4 4 6
	4 4 1
	4 4 12

*/

#include <iostream>
#include <cmath>
#include <list>
#include <iterator>
using namespace std;

/**
 *  1. find area of triangle by Heron's formula
 *  2. sort array of results
 *  3. output sort array
 *
 *  @param {int} a - a side of triangle
 *  @param {int} b - b side of triangle
 *  @param {int} c - c side of triangle
 *  @return {int} 0/1 - success/error result
 */

int calculateTriangle(double a, double b, double c) {
	double area, perimeter;

	perimeter = (a + b + c) / 2.0;
	area = sqrt(perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c));

	double results[4] = {a, b, c, area};
	sort(results, results + 4);

	for(int i = 0; i < 4; i++){
		cout << results[i] << endl;
	}

	return 0;
}



int main()
{
	cout << "Hello! Please, write 3 values:\n";

	int stop;

	double a, b, c;
	cin >> a >> b >> c;

	double resort[3] = {a, b, c};
	sort(resort, resort + 3);

	a = resort[0];
	b = resort[1];
	c = resort[2];

	// find the cos(a) of angle between two equal sides
	double cosa = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);

	if (a + b <= c) {
		cout << "Not a triangle!" << endl;
	} else if (cosa <= 0) {
		cout << "Not acute triangle!" << endl;
	} else {
		cout << "Correct acute triangle!" << endl << endl;
		cout << "cosa = " << cosa << endl;
		calculateTriangle(a, b, c);
	}

	cin >> stop;
  return 0;
}
