#include "struct.h"
#include "str_function.h"
#include "CityList_function.h"
#include "Route_function.h"
int main()
{
	int a;
	CityList_FileInit();
	CityList* p;
	p = CityList_init();
	Route* q;
	q = Route_init();
	q=Route_create(q, p);
	Route_save(q);
}