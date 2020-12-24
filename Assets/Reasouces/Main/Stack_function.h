#include "struct.h"
stack stack_init()
{
	stack stack;
	stack.head = 0;
	memset(stack.stack, 0, 5);
	return stack;
}
void stack_push(stack* S,int data)
{
	S->stack[S->head] = data;
	S->head++;
}
int stack_pull(stack* S)
{
	int data;
	data = S->stack[S->head--];
	S->head--;
	return data;
}
#pragma once
