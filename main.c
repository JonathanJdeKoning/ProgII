#include "dicegame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	// Initialize necessary variables
	srand(time(NULL));
	int playerOnePoints = 0;
	int playerTwoPoints = 0;
	int currPlayer = 1;
	int numRounds;
	int roundNumber;

	// Get number of rounds
	printf("Enter the number of rounds: ");
	scanf("%d", &numRounds);

	printPlayerPoints(playerOnePoints, playerTwoPoints);

	// Loop for number of rounds
	for (roundNumber = 1; roundNumber <= numRounds; roundNumber++)
	{
		enum ROUNDTYPE roundType = getRoundType();
		int roundPoints = getRoundPoints(roundType);
		int diceRoll = getDiceRoll();

		// Print round header info
		printf("\nROUND %d\n", roundNumber);
		printf("---------\n");
		printf("Player  : %d\n", currPlayer);
		printRoundInfo(roundType, diceRoll, roundPoints);

		// Determine parity of dice roll
		int result = diceRoll%2;

		// Update scores based on parity
		if (currPlayer == 1)
			playerOnePoints += roundPoints * ((result * 2) - 1);
		else
			playerTwoPoints -= roundPoints * ((result * 2) - 1);

		// Print new scores and swap player based on parity
		printPlayerPoints(playerOnePoints, playerTwoPoints);
		currPlayer = 2 - result;
	}
	
	// Print End info
	printf("\nGAME OVER!!\n");
	if (playerOnePoints > playerTwoPoints)
		printf("p1 Won\n");
	else if (playerTwoPoints > playerOnePoints)
		printf("p2 Won\n");
	else
		printf("Tie\n");
	
	return 0;
}
