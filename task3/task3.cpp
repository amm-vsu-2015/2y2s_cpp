
/**

	Даны целые чиста а1...an.
	Если в данной последовательности ни одно четное число не расположено после нечетного,
	то получить все отрицательные члены последовательности,
	иначе – все положительные.

	Порядок следования чисел последовательности меняется на обратный.

	Входные данные для проверки:

	Для 10 чисел:

	6 7 2 1 120 3 6 672 74 5
	6 2 1 2 4 6 78 672 19 3

	=> min: 5.

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


void insertItem(List* list, int value) {
	if (list == nullptr) {
		list = new List();
		list->value = value;
		list->next = nullptr;
		list->prev = nullptr;
	} else {
		list->next = new List();
		list->next->value = value;
		list->next->prev = list;
		list->next->next = nullptr;
		list = list->next;
	}
}


void findFirst(List* list) {
	std::cout << "123" << '\n';
	while (list->prev != nullptr) list = list->prev;
	std::cout << "123" << '\n';
	// return list;
}

void findLast(List* list) {
	while (list->next != nullptr) list = list->next;
	// return list;
}

void printList(List* list, int isNegative) {
	while (list != nullptr) {
		cout << list->value;
		list = list->prev;
	}
}

int oddListCheck(List* list) {
	// Если в данной последовательности ни одно четное число не расположено после нечетного,
	while (list->next != nullptr) {
		if (list->value % 2 == 1 && list->next->value % 2 == 0) {
			return 1;
		}
		cout << list->value;
		list = list->next;
	}

	return 0;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	List* list = nullptr;
	List* head = nullptr;
	List* last = nullptr;
	int count = 0;

	cout << "How much items you need? ";
	cin >> count;

	int value = 0;
	while (count--) {
		cout << "Write new item: ";
		cin >> value;
		insertItem(list, value);
	}
	std::cout << "1" << '\n';
	head = list;
	last = list;
	findFirst(head);
	std::cout << "-" << '\n';
	findLast(last);


	std::cout << "2" << '\n';
	list = head;
	int isNegative = oddListCheck(list);

	swap(last, head);

	list = head;
	printList(list, 1);

	int stop;
	cin >> stop;
  return 0;
}
