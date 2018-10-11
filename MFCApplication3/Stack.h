#pragma once
#ifndef STACK_H
#define STACK_H
#include"stdafx.h"
#define MaxSize 100

class Stack
{
	char ch[MaxSize];
	int top;

public:
	Stack();
	bool IsEmpty();
	bool IsFull();
	char GetTop();
	void Push(char c);
	char Pop();
	void Clear();
};
#endif