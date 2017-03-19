
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

	// cout << "area = " << area << "; ";
	// cout << "perimeter = " << perimeter << "; ";
	// cout << "a + b + c = " << a + b + c << endl;

	double results[4] = {a, b, c, area};
	sort(results, results + 4);

	for(int i = 0; i < 4; i++){
		cout << results[i] << endl;
	}

	return 0;
}



int main()
{
	cout << "Hello! Please, write 3 values:(a, b, c)\n";

	int stop;

	double a, b, c;
	cin >> a >> b >> c;

	if (!(a == b || a == c || b == c)) {
		cout << "All sides of triangle is different! " << endl;
		cin >> stop;
		return 0;
	}

	// find the cos(a) of angle between two equal sides
	double cosa = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);

	if (a + b <= c) {
		cout << "Not a triangle!" << endl;
	} else if (cosa <= 0) {
		cout << "Rectangular triangle!" << endl;
	} else {
		cout << "Right triangle!" << endl << endl;
		cout << "cosa = " << cosa << endl;
		calculateTriangle(a, b, c);
	}

	cin >> stop;
  return 0;
}
