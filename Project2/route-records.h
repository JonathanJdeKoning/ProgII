#include <stdio.h>
#ifndef routeRecords
#define routeRecords

typedef enum SearchType { ROUTE, ORIGIN, DESTINATION, AIRLINE } SearchType;

typedef struct {
    char origin[4];
    char dest[4];
    char airline[3];
    int passengerCounts[6];

} RouteRecord;


void printMenu() 


RouteRecord* createRecords(FILE* fileIn) 


int fillRecords(RouteRecord* r, FILE* fileIn)


int findAirlineRoute(RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx)


void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st) 
#endif
