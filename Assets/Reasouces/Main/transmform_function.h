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
	int len = S->length;
	for (int i = 0; i < len; i++)
	{
		str[i] = S->str[i];
	}
		str[len] = '\0';
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
void SiteNumber2int(string SiteNumber, int& x, int& y)
{
	char str[100];
	x = SiteNumber.str[SiteNumber.length - 1] - 'A';	//此处由于实际民航座位编号视机型而定，内容过于复杂故将其简易化
	SiteNumber.str[SiteNumber.length - 1] = '/0';
	string2char(str, &SiteNumber);
	y = char2int(str);
}
#pragma once
