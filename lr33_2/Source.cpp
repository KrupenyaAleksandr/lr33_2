#include "header.h"

int main() {
	setlocale(LC_ALL, "RU");
	element* head = NULL;
	int a;

	makeList(head);
	cout << "Исходный список: " << endl;
	printList(head);
	sortList(head);
	cout << "Отсортированный список: " << endl;
	printList(head);
	cout << "Введите элемента, который необходимо вставить: ";
	cin >> a;
	add(head, a);
	cout << "Список после вставки элемента: " << endl;
	printList(head);
	cout << "Конечный список: " << endl;
	deleteRepeat(head);
	printList(head);

	return 0;
}