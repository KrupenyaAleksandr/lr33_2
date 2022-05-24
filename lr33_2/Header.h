#pragma once
#ifndef header
#define header

#include <iostream>
#include <malloc.h>
#include <conio.h>
#include <locale.h>
#include <string>

struct element {
	int num;
	element* previous = NULL;
	element* next = NULL;
};

void makeList(element*& Head);
void printList(element*& Head);
void sortList(element*& Head);
void add(element*& Head, int x);
void deleteRepeat(element*& Head);

using namespace std;

#endif