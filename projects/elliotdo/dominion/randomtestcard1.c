/*
  Author:     Donald Elliott
  Class:      CS362-400
  Due Date:   11/05/17
  Assignment: 4 (Village Random Test File)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomTest(struct gameState *game) {
  int i, player;
  game->whoseTurn = rand() % 2;
  // Generate random hands, turns, decks, and discard
  int maxRandHand = rand() % (500 + 1);
  int maxRandTurn = rand() % (16 + 1);
  int maxRandDeck = rand() % (500 + 1);
  int maxRandDiscard = rand() % (500 + 1);

  game->hand[game->whoseTurn][0] = 7;
  game->handCount[game->whoseTurn] = maxRandHand;
  for(i = 1; i < game->handCount[game->whoseTurn]; i++)
    game->hand[game->whoseTurn][i] = maxRandTurn;

  game->deckCount[game->whoseTurn] = maxRandDeck;
  for(i = 0; i < game->deckCount[game->whoseTurn]; i++)
    game->deck[game->whoseTurn][i] = maxRandTurn;

  game->discardCount[game->whoseTurn] = maxRandDiscard;
  for(i = 0; i < game->discardCount[game->whoseTurn]; i++)
    game->discard[game->whoseTurn][i] = maxRandTurn;

  //Set up hand for an opponent
  if(game->whoseTurn == 0)
    player = 1;
  else
    player = 0;

  game->handCount[player] = maxRandHand;
  for(i = 0; i < game->handCount[player]; i++)
    game->hand[player][i] = maxRandTurn;

  game->deckCount[player] = maxRandDeck;
  for(i = 0; i < game->deckCount[player]; i++)
    game->deck[player][i] = maxRandTurn;

  game->discardCount[player] = maxRandDiscard;
  for(i = 0; i < game->discardCount[player]; i++)
    game->discard[player][i] = maxRandTurn;
}

int main() {
	int count = 1;
	srand(time(NULL));
	int seed = rand() % 100 + 1;
  int randLoop = rand() % 80 + 21;
	int numPlayers = 2;
  int beforeHand, afterHand, beforeAction, afterAction;
	struct gameState game;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	initializeGame(numPlayers, k, seed, &game);
	game.phase = 0;
	game.numBuys = 1;
	// Start Loop
	int j;
	for(j = 0; j < randLoop; j++){
		// Begin Random Game
    printf("|============================|\n");
    printf("|       Random Test %d      \n", count);
    printf("|----------------------------|\n");
		randomTest(&game);
		struct gameState gameBefore;
		gameBefore = game;
    game.numActions = 1;
    printf("|      Before Using Card     |\n");
    printf("|----------------------------|\n");
    printf("| Hand Count: %d\n", game.handCount[game.whoseTurn]);
    printf("| Number of Actions: %d\n", game.numActions);
    beforeAction = game.numActions;
    beforeHand = game.handCount[game.whoseTurn];
		cardEffect(village, 0, 0, 0, &game, 0, 0);
    printf("|----------------------------|\n");
    printf("|      After Using Card      |\n");
    printf(" ----------------------------|\n");
    printf("| Hand Count: %d\n", game.handCount[game.whoseTurn]);
    printf("| Number of Actions: %d\n", game.numActions);
    afterAction = game.numActions;
    afterHand = game.handCount[game.whoseTurn];
    if (beforeHand == afterHand && beforeAction == afterAction-2)
      printf("| ALL TESTS PASSED\n\n");
    else {
      printf("| TESTS FAILED.\n");
    }
		count++;
	}
  return 0;
}
