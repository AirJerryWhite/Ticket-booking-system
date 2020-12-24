#include "struct.h"
#include "str_function.h"
int main()
{
	string a,b;
	str_create(&a);
	str_copy(&b, a);
	str_show(b);
}