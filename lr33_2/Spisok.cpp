#include "header.h"

void makeList(element*& Head) {
	string str;
	int x;
	cout << "Ввод элементов через enter, \"stop\" для остановки" << endl;
	getline(cin, str);
	if (str != "stop") {
		x = stoi(str);
		element* cur, *previous = NULL;
		Head = new(element);
		cur = Head;
		Head->num = x;
		Head->previous = NULL;
		Head->next = NULL;
		while (true) {
			getline(cin, str);
			if (str == "stop") break;
			x = stoi(str);
			previous = cur;
			cur = new(element);
			cur->num = x;
			cur->previous = previous;
			previous->next = cur;
			cur->next = NULL;
		}
	}
}

void printList(element*& Head) {
	if (Head != NULL){
		element* cur = Head;
		cout << cur->num << ' ';
		while (cur->next != NULL) {
			cur = cur->next;
			cout << cur->num << ' ';
		}
		cout << endl;
	}
}

void sortList(element*& Head) {
	element* tmp = Head;
	bool flag = true;
	int a;
	while (flag) {
		flag = false;
		while (tmp->next != NULL) {
			if (tmp->next->num < tmp->num) {
				a = tmp->num;
				tmp->num = tmp->next->num;
				tmp->next->num = a;
				flag = true;
			}
			tmp = tmp->next;
		}
		tmp = Head;
	}
}

void add(element*& Head, int x) {
	if (Head != NULL) {
		element* cur = Head, *addelement;
		addelement = new(element);
		addelement->num = x;
		while (cur->num < x && cur->next != NULL) {
			cur = cur->next;
		}

		if (cur->previous == NULL) {
			cur->previous = addelement;
			addelement->next = cur;
			addelement->previous = NULL;
			Head = addelement;
		}
		else {
			if (cur->num > x)cur = cur->previous;
			addelement->next = cur->next;
			addelement->previous = cur;
			cur->next = addelement;
		}
	}
}

void deleteRepeat(element*& Head) {
	if (Head != NULL) {
		element* cur = Head, *del = NULL;
		bool flag = true, delflag = true;
		while (flag) {
			flag = false;
			while (cur->next != NULL) {
				if (cur->next->num == cur->num) {
					if (cur->previous == NULL) {
						Head = cur->next;
						cur->next->previous = NULL;
					}
					else {
						cur->next->previous = cur->previous;
						cur->previous->next = cur->next;
					}
					del = cur->next;
					free(cur);
					cur = del;
				}
				cur = cur->next;
			}
			cur = Head;
		}
	}
}