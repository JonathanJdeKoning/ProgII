#include "dicegame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getRandomNumber(int min, int max) {
	return rand() % (max + 1 - min) + min;
}


int getDiceRoll() {
	return getRandomNumber(1,6);
}


enum ROUNDTYPE getRoundType() {
	switch (getRandomNumber(0,9)){
		case 0: return DOUBLE;
		case 1: return DOUBLE;
		case 2: return DOUBLE;
		case 3: return BONUS;
		case 4: return BONUS;
	}
	return REGULAR;
}


int getRoundPoints(enum ROUNDTYPE roundType) {
	int points = 10 * getRandomNumber(1,10);
	if (roundType == DOUBLE) 
		points *= 2;
	if (roundType == BONUS) 
		points = 200;
	return points;
}


void printPlayerPoints(int p1, int p2) {
	printf("P1      : %d\n", p1);
	printf("P2      : %d\n", p2);
}


void printRoundInfo(enum ROUNDTYPE t, int dice, int points) {
	char roundType[8];
	strcpy(roundType, "REGULAR");
	
	if (t == DOUBLE)
		strcpy(roundType,"DOUBLE");
	if (t == BONUS) 
		strcpy(roundType, "BONUS");

	printf("Type    : %s\n", roundType);
	printf("DICE    : %d\n", dice);
	printf("POINTS  : %d\n", points);
}


