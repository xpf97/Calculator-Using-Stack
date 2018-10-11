#pragma once
#ifndef STACKNUM_H
#define STACKNUM_H
#include"stdafx.h"
#define MaxSize 100

class Stacknum
{
	double num[MaxSize];
	int top;

public:
	Stacknum();
	bool IsEmpty();
	bool IsFull();
	double GetTop();
	void Push(double c);
	double Pop();
	void Clear();
};
#endif#pragma once
