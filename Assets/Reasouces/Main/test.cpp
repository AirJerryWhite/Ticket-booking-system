#include "struct.h"
#include "str_function.h"
#include "CityList_function.h"
int main()
{
	string city;
	CityList* head;
	head = CityList_init();
	head = CityList_create(head);
	CityList_display(head);
	str_create(&city);
	head = CityList_add(head, city);
	CityList_display(head);
	CityList_save(head);
}