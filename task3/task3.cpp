
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

const int LAB_SIZE = 25;

// base
struct Position;
struct Stack;

void printLabirint(int lab[LAB_SIZE][LAB_SIZE], Position* personAt = nullptr);
void generateLabirint(int lab[LAB_SIZE][LAB_SIZE]);
Position* setPerson(int lab[LAB_SIZE][LAB_SIZE]);

// Stack
Stack* push(Stack* stack, Position* position);
Stack* pop(Stack* stack);

// walking
Stack* lookAround(int lab[LAB_SIZE][LAB_SIZE], Stack* mainStack, Stack* cell);
void changeCell(int lab[LAB_SIZE][LAB_SIZE], Position* position, int value);
int checkCell(int lab[LAB_SIZE][LAB_SIZE], Position* cell);
void walk(int lab[LAB_SIZE][LAB_SIZE], Position* personAt);

struct Position {
	int x;
	int y;

	Position(int X, int Y) {
		x = X;
		y = Y;
	}
};



void printLabirint(int lab[LAB_SIZE][LAB_SIZE], Position* personAt) {
	for (int i = 0; i < LAB_SIZE - 1; i++) {
		for (int j = 0; j < LAB_SIZE - 1; j++) {
			char outChar;

			switch (lab[i][j]) {
				case 0:
					outChar =  '-';
					break;
				case 1:
					outChar =  'X';
					break;
				case 2:
					outChar = '*';
					break;
				default:
					break;
			}

			if (personAt != nullptr && personAt->x == i && personAt->y == j) {
				outChar = '!';
			}

			std::cout << outChar << "  ";
		}
		std::cout << '\n';
	}
}

void generateLabirint(int lab[LAB_SIZE][LAB_SIZE]) {
	srand(time(NULL));
	for (int i = 0; i < LAB_SIZE - 1; i++) {
		for (int j = 0; j < LAB_SIZE - 1; j++) {
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
	std::cout << x << y << '\n';
	return new Position(x, y);
}



struct Stack {
	Position* position;
	Stack* next = nullptr;
};

Stack* push(Stack* stack, Position* position) {
	Stack* newStack = new Stack();
	newStack->position = position;

	if (stack != nullptr) {
		newStack->next = stack;
	}

	return newStack;
}

Stack* pop(Stack* stack) {
	Stack* popped = stack;
	stack = stack->next;

	return popped;
}


void walk(int lab[LAB_SIZE][LAB_SIZE], Position* personAt) {

	Stack* stack = push(nullptr, personAt);
	changeCell(lab, personAt, 2);

	while(stack != nullptr) {
		Stack* popped = stack;
		stack = stack->next;
		stack = lookAround(lab, stack, popped);
	}
}


Stack* lookAround(int lab[LAB_SIZE][LAB_SIZE], Stack* mainStack, Stack* cell) {
	Position* cellPosition = cell->position;

	// check around of cell
	for (int idx_x = -1; idx_x < 2; idx_x++) {
		for (int idx_y = -1; idx_y < 2; idx_y++) {
			Position* position = new Position(cellPosition->x + idx_x, cellPosition->y + idx_y);

			if (checkCell(lab, position)) {
				changeCell(lab, position, 2);
				mainStack = push(mainStack, position);
			}
		}
	}

	return mainStack;
}

void changeCell(int lab[LAB_SIZE][LAB_SIZE], Position* position, int value) {
	lab[position->x][position->y] = value;
}

int checkCell(int lab[LAB_SIZE][LAB_SIZE], Position* cell) {
	int isX_correct = (cell->x < LAB_SIZE-1 && cell->x >= 0);
	int isY_correct = (cell->y < LAB_SIZE-1 && cell->y >= 0);

	return (isX_correct && isY_correct && lab[cell->x][cell->y] == 0);
}


int main()
{
	setlocale(LC_ALL, "Russian");

	int Labirint[LAB_SIZE][LAB_SIZE];

	generateLabirint(Labirint);

	std::cout << "Preview board: " << '\n';
	printLabirint(Labirint);

	Position* personAt = setPerson(Labirint);

	walk(Labirint, personAt);

	std::cout << "Result board: " << '\n';
	printLabirint(Labirint, personAt);

	int stop;
	cin >> stop;
  return 0;
}
