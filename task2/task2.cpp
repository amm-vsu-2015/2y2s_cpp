
/**

	Даны целые чиста а1...an.
	Если в данной последовательности ни одно четное число не расположено после нечетного,
	то получить все отрицательные члены последовательности,
	иначе – все положительные.

	// если хотя бы одно четное число расположено после нечетного,
	// т.е. после начала нечетных идут только нечетные, то вывести отрицательные

	Порядок следования чисел последовательности меняется на обратный.

	Входные данные для проверки:

*/

#include <iostream>
using namespace std;

struct List {
	int value;
	List* next;
	List* prev;
};

// struct Stack {
// 	int value;
// 	List* next;
// };
//
// void pushStack(Stack* &stack; int value) {
// 	if (stack == nullptr) {
// 		stack = new Stack();
// 		stack->value = value;
// 	} else {
// 		stack->next = new Stack();
// 		stack->next->value = value;
// 		stack = stack->next;
// 	}
// }
//
// int popStack(Stack* &stack) {
// 	int lastValue = stack->value;
// 	stack = stack->next;
// 	return lastValue;
// }


List* insertItem(List* list, int value) {
	List* newItem = new List();
	newItem->value = value;
	newItem->next = nullptr;

	if (list == nullptr) {
		newItem->prev = nullptr;
	} else {
		newItem->prev = list;
		newItem->prev->next = newItem;
	}

	return newItem;
}


List* findFirst(List* list) {
	while (list->prev != nullptr) list = list->prev;
	return list;
}

List* findLast(List* list) {
	while (list->next != nullptr) list = list->next;
	return list;
}

void printList(List* list, int isNegative) {
	while (list != nullptr) {
		if (!isNegative && list->value >= 0) {
			cout << list->value << '\n';
		}

		if (isNegative && list->value < 0) {
			cout << list->value << '\n';
		}

		list = list->prev;
	}
}

int oddListCheck(List* list) {
	int check = 0;
	while (list->next != nullptr) {
		if (list->value % 2 != 0 && list->next->value % 2 == 0) {
			check = 1;
		}
		list = list->next;
	}

	return check;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	List* list = nullptr;
	List* head = nullptr;
	List* last = nullptr;
	int count = 0;

	while (count < 2) {
		cout << "How much items you need? ";
		cin >> count;
		if (count < 2) {
			std::cout << "Hi, please write count more than 1. thanks <3" << '\n';
		}
	}

	int value = 0;
	while (count--) {
		cout << "Write new item: ";
		cin >> value;
		list = insertItem(list, value);
	}

	head = findFirst(list);
	last = findLast(list);

	list = head;
	int isNegative = !oddListCheck(list);

	list = last;
	printList(list, isNegative);

	int stop;
	cin >> stop;
  return 0;
}
