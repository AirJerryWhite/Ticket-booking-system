#include "struct.h"
#include "function.h"
int main()
{
	int flag;
	string s, t;
	strcreate(&s);
	strcreate(&t);
	flag=strcompare(s, t);
	printf("%d", flag);
}