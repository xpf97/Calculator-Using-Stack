#include"stdafx.h"
#include"Stack.h"
Stack::Stack()
{
	top = -1;
};

bool Stack::IsEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

bool Stack::IsFull()
{
	if (top == MaxSize - 1)
		return true;
	else
		return false;
}

char Stack::GetTop()
{
	return ch[top];
}

void Stack::Push(char c)
{
	ch[++top] = c;
}

char Stack::Pop()
{
	return ch[top--];
}

void Stack::Clear()
{
	top = -1;
}
