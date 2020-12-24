#include "struct.h"
#include "str_function.h"
#include "CityList_function.h"
int main()
{
	CityList* head;
	head = CityList_init();
	head=CityList_create(head);
	CityList_refresh(head);
	CityList_display(head);
	CityList_save(head);
}