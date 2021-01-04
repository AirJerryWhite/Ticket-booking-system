#include "struct.h"
#include "Stack_function.h"

void char2string(string* S, char* str)
{
	int length = 0;
	for (int i = 0; i < 100; i++)
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			S->str[i] = '\0';
			break;
		}
		else
		{
			S->str[i] = str[i];
			length++;
		}
	}
	S->length = length;
}
void string2char(char* str, string* S)
{
	for (int i = 0; i < S->length; i++)
	{
		if (i == S->length)
		{
			str[i] = '\n';
			str[i + 1] = '\0';
		}
		else str[i] = S->str[i];
	}
	str[S->length] = '\0';
}
void int2char(int length, char* str)
{
	stack stack;
	stack = stack_init();
	int len,stack_len;
	len = length;
	do
	{
		stack_push(&stack, len % 10);
		len = len / 10;
	} while(len!=0);
	stack_len = stack.head;
	for (int i = 0; i < stack_len; i++)
	{
		str[i] = stack_pull(&stack) + '0';
	}
	str[stack_len] = '\0';
}
int char2int(char* str)
{
	int len=0;
	for (int i = 0; i < 10; i++)
	{
		if (str[i] == '\n' || str[i] == '\0') break;
		else
		{
			len = len * 10 + (str[i] - '0');
		}
	}
	return len;
}
#pragma once
