#include "system.h"
#include "transmform_function.h"
int main()
{
	FlightList* flightlist;
	flightlist = FlightList_init();
	flightlist = FlightList_create(flightlist);
	CityList* citylist;
	citylist = CityList_init();
	citylist = CityList_create(citylist);
	Route* route;
	route = Route_init();
	route = Route_create(route, citylist, flightlist);
	//menu();
}