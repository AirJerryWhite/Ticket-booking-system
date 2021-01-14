#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
//=============================stack==============================//
typedef struct stack
{
	int stack[1000];
	int head;
}stack;
stack stack_init();
void stack_push(stack* S,int data);
int stack_pull(stack* S);
//============================string==============================//
typedef struct string
{
	char str[100]={};
	int length=0;
}string;
string str_init();
void str_create(string* S);
void str_copy(string* S,string T);
int str_compare(string S, string T);
void str_display(string S);	/*for test*/
void str_refresh(string* S);
//===========================CityList==============================//
typedef struct CityList
{
	int No=0;
	string city;
	struct CityList* next=NULL;
}CityList;
void CityList_FileInit();
CityList* CityList_init();
void CityList_refresh(CityList* head);
CityList* CityList_create(CityList* head);
CityList* CityList_add(CityList* head, string city);
void CityList_display(CityList* head);	/*for test*/
int CityList_find(CityList* head, string city);
void CityList_save(CityList* head, string path);
//===========================DestinationList==============================//
typedef struct DestinationList
{
	int No;
	string origin;
	string city;
	string FlightNumber;
	string date;
	string time;
	int money;
	int seat;
	string SeatNumber;
	struct DestinationList* next = NULL;
}DestinationList;
DestinationList* Dest_init();
void Dest_refrsh(DestinationList* p);
DestinationList* Dest_add(DestinationList* head, string origin, string city, string FlightNumber, string date, string time, int money, int seat);
DestinationList* Dest_remove(DestinationList* head, string FlightNumber);
DestinationList* Dest_find_FlightNumber(DestinationList* head, string FlightNumber);
DestinationList* Dest_find_City(DestinationList* head, string city);
void Dest_display(DestinationList* head);
//============================SeatList==============================//
typedef struct SeatList
{
	int No;
	string date;
	string time;
	bool** seat;
	SeatList* next;
}SeatList;
SeatList* SeatList_init();
SeatList* SeatList_loadSite(SeatList* head, string date, string time, string Site);
SeatList* SeatList_add(SeatList* head,string date,string time,int x, int y);
void SeatList_refresh(SeatList* head);
SeatList* SeatList_find(SeatList* head, string date, string time);
SeatList* SeatList_bookingSite(SeatList* head, string date, string time, string SiteNumber, bool& success);
SeatList* SeatList_edit(SeatList* head, string date, string new_date, string time, string new_time);
SeatList* SeatList_refund(SeatList* head, string date, string time, string SiteNumber);
SeatList* SeatList_remove(SeatList* head, string date, string time);
//===========================FlightList=============================//
typedef struct FlightList
{
	int No;
	string FlightNumber;
	SeatList* Site;
	FlightList* next;
}FlightList;
FlightList* FlightList_init();
void FlightList_refresh(FlightList* head);
FlightList* FlightList_create(FlightList* head);
FlightList* FlightList_add(FlightList* head, string FlightNumber, string date, string time, int x, int y);
FlightList* FlightList_find(FlightList* head, string FlightNumber);
FlightList* FlightList_edit(FlightList* head, string FlightNumber, string date, string new_date, string time, string new_time);
FlightList* FlightList_refund(FlightList* head, string FlightNumber, string date, string time,string SiteNumber);
FlightList* FlightList_remove(FlightList* head, string FlightNumber, string date, string time);
void FlightList_save(FlightList* head);
//===========================Route=============================//
typedef struct Route
{
	int No;
	string city;
	DestinationList* Destination;
	Route* Next;
}Route;
Route* Route_init();
void Route_refresh(Route* p);
Route* Route_create(Route* head, CityList* citylist, FlightList* flightlist);
Route* Route_add_city(Route* head, string city);
Route* Route_add_flight(Route* head, string origin, string city, string FlightNumber, string date, string time, int money, int seat,string path);
void Route_transfer(Route* head, string origin, string transfer, string city, string FlightNumber, string date, string transfer_date, string time, string transfer_time, int money_origin2city, int money_origin2transfer, int money_transfer2city, int seat, int transfer_seat);
Route* Route_find(Route* head, string city);
void Route_save(Route* head, string path);
//============================accout==============================//
typedef struct Account
{
	int No;
	string username;
	string passport;
	Route* Flight;
	Account* next;
}Account;
Account* account_init();
void account_refresh(Account* head);
Account* account_create(Account* head);
void account_input();
void account_edit(Account* head, string username, string newpassport);
void account_FileInit();
Account* account_find(Account* head, string username);
Account* account_add(Account* head, string username, string passport);
void account_save(Account* head);
int account_login(Account* head, string username, string passport);
void account_display(Account* head);
void encryp_passport(string* passport);
string decrypt_passpore(string passport);
//===========================transform=============================//
void char2string(string* S, char* str);
void char2string(string* S, const char* str)
void string2char(char* str, string* S);	
void int2char(int length, char* str);
int char2int(char* str);
void SeatNumber2int(string SiteNumber, int& x, int& y);
#pragma once
