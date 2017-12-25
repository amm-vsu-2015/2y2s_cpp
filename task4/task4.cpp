
/**

	Создать линейный однонаправленный список из вещественных чисел.
	Удалить из списка элемент, после каждого элемента с положительным значением.

	Входные данные для проверки:
	->    -1 2 4 -2 0 -2 4 4 4 -2 -2 -3 (12 items)
*/

#include <iostream>
using namespace std;

struct Stack {
	double value;
	Stack* next;

	Stack(double val) {
		value = val;
		next = nullptr;
	}
};

void push(Stack** stack, double value) {
	Stack* newItem = new Stack(value);

	newItem->next = *stack;
	*stack = newItem;
}

void print(Stack* stack) {
	while (stack != nullptr) {
		std::cout << stack->value << '\n';
		stack = stack->next;
	}
}

void remove(Stack* stack) {
	while (stack->next != nullptr) {
		if (stack->value >= 0) {
			stack->next = stack->next->next;
		}
		stack = stack->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int count = 0;

	std::cout << "How many items you need? ";
	std::cin >> count;

	Stack* stack = nullptr;
	Stack** head = &stack;

	while (count--) {
		double value;
		std::cout << "Please, write value for new item: ";
		std::cin >> value;

		push(&stack, value);
	}

	remove(*head);
	print(*head);

	int stop;
	cin >> stop;
  return 0;
}
