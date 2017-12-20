
/**

	Дана логическая матрица, описывающая лабиринт и начальное состояние человека
	в лабириние (x,y).

	Необходимо предложить Любой вариант обхода всех доступных клеток лабиринта.

	Лабаринт – массив, где true - стена, а false - проход.

	Задача на тему стеков. Реализовать нужно через эти структуры.

	Входные данные для проверки:
	- генерируемый динамически лабиринт
	- только одно состояние лабиринта

*/

#include <iostream>
using namespace std;

const int LAB_SIZE = 20;
int Labirint[LAB_SIZE][LAB_SIZE];

struct Position {
	int x;
	int y;

	Position(int X, int Y) {
		x = X;
		y = Y;
	}

	// int operator==(const array[LAB_SIZE][LAB_SIZE]& lhs, const Position& rhs) {
	//     return ((lhs))
	// }
};

void printLabirint(int lab[LAB_SIZE][LAB_SIZE], Position* personAt = nullptr) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char outChar;
			if (lab[i][j]) {
				outChar =  'X';
			} else {
				outChar =  '-';
			}

			if (personAt != nullptr && personAt->x == i && personAt->y == j && !lab[i][j]) {
				outChar = '!';
			}

			std::cout << outChar << "  ";
		}
		std::cout << '\n';
	}
}

void generateLabirint(int lab[LAB_SIZE][LAB_SIZE]) {
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			lab[i][j] = ((rand() % 100 + 1) % 2 == 0);
		}
	}
}

Position* setPerson(int lab[LAB_SIZE][LAB_SIZE]) {
	int x, y;

	do {
		std::cout << "Please, set person position: (x, y) " << '\n';

		std::cin >> x >> y;
		x--; y--;

		if (lab[x][y]) {
			std::cout << "Bad position, this is wall. try again..." << '\n';
		}
	} while (lab[x][y]);

	return new Position(x, y);
}

void walk(int lab[LAB_SIZE][LAB_SIZE]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			lab[i][j] = ((rand() % 100 + 1) % 2 == 0);
		}
	}
}

Graph* buildLabitintMap(int lab[LAB_SIZE][LAB_SIZE]) {
	// generate tree
}

struct Graph {
	int checked;
	Graph* left;
	Graph* right;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	generateLabirint(Labirint);
	printLabirint(Labirint);

	Position* personAt = setPerson(Labirint);
	printLabirint(Labirint, personAt);

	walk(Labitint)

	int stop;
	cin >> stop;
  return 0;
}
