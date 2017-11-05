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

int main() {
  srand(time(NULL));
  struct gameState g;
  int i, j, player_num, allcard, seedIt;
  int beforeHand, beforeCard, beforeCoin, beforeDiscard, beforeAction, afterAction, afterHand, afterCard, afterCoin, afterDiscard;
  int k[10] = {village, adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, steward};
  seedIt = rand() % 80 + 21;
  //Tests could be from 10 to 100
  int maxTests = rand() % 91 + 10;
  for (i = 0; i < maxTests; i++){
    player_num = rand()% 2; // 2 to 3 players
    printf("|============================|\n");
    printf("|       Random Test %d      \n", i+1);
    printf("|----------------------------|\n");
    j = initializeGame(player_num, k, seedIt, &g);
    // Used assert for testing build
    //assertForRandom(j == 0, "Initialization Failed");
    g.deckCount[player_num] = rand() % 500 + 1;
    g.discardCount[player_num] = rand() % 500 + 1;
    g.handCount[player_num] = rand() % 500 + 1;
    g.numActions = 1;
    // Random coin amount from 5 - 19
    g.coins = rand() % 10 + 5;
    allcard = g.handCount[player_num] + g.deckCount[player_num];
    printf("|      Before Using Card     |\n");
    printf("|----------------------------|\n");
    printf("| Hand Count: %d\n", g.handCount[player_num]);
    beforeHand = g.handCount[player_num];
    printf("| Discard Count: %d\n", g.discardCount[player_num]);
    beforeDiscard = g.discardCount[player_num];
    printf("| Card Number: %d\n", allcard);
    beforeCard = allcard;
    printf("| Coin Number: %d\n", g.coins);
    beforeCoin = g.coins;
    printf("| Number of Actions: %d\n", g.numActions);
    beforeAction = g.numActions;
    j = cardEffect(village, 0, 0, 0, &g, 0, 0);
    allcard = g.handCount[player_num] + g.deckCount[player_num];
    printf("|----------------------------|\n");
    printf("|      After Using Card      |\n");
    printf(" ----------------------------|\n");
    printf("| Hand Count: %d\n", g.handCount[player_num]);
    afterHand = g.handCount[player_num];
    printf("| Discard Count: %d\n", g.discardCount[player_num]);
    afterDiscard = g.discardCount[player_num];
    printf("| Card Number: %d\n", allcard);
    afterCard = allcard;
    printf("| Coin Number: %d\n", g.coins);
    afterCoin = g.coins;
    printf("| Number of Actions: %d\n", g.numActions);
    afterAction = g.numActions;
    if (beforeCoin == afterCoin && beforeDiscard == afterDiscard && beforeCard == afterCard
        && beforeHand == afterHand && beforeAction == afterAction - 2)
      printf("| ALL TESTS PASSED\n\n");
    else
      printf("| TEST FAILURE\n\n");
  }
  return 0;
}
