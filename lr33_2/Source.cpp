#include "header.h"

int main() {
	setlocale(LC_ALL, "RU");
	element* head = NULL;
	int a;

	makeList(head);
	cout << "�������� ������: " << endl;
	printList(head);
	sortList(head);
	cout << "��������������� ������: " << endl;
	printList(head);
	cout << "������� ��������, ������� ���������� ��������: ";
	cin >> a;
	add(head, a);
	cout << "������ ����� ������� ��������: " << endl;
	printList(head);
	cout << "�������� ������: " << endl;
	deleteRepeat(head);
	printList(head);

	return 0;
}