#include"stdafx.h"
#include"Stacknum.h"
Stacknum::Stacknum()
{
	top = -1;
};

bool Stacknum::IsEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

bool Stacknum::IsFull()
{
	if (top == MaxSize - 1)
		return true;
	else
		return false;
}

double Stacknum::GetTop()
{
	return num[top];
}

void Stacknum::Push(double c)
{
	num[++top] = c;
}

double Stacknum::Pop()
{
	return num[top--];
}

void Stacknum::Clear()
{
	top = -1;
}
