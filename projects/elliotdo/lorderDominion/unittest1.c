/*
  Author:   Donald Elliott
  Class:    CS362-400
  Testing:  buyCard()
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

int main() {
  int passed = 0;
  int p1 = 1;
  // Make sure we have enough money to buy a silver.
  int money1 = 4;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, great_hall};
  struct gameState G;
  initializeGame(2, k, 100, &G);

  //Start test
  printf("\nTesting buyCard()\n");
  G.whoseTurn = p1;
  G.coins = money1;
  buyCard(silver, &G);
  printf("Player 1 bought silver.\n");
  printf("Top of discard: %d.\n", G.discard[G.whoseTurn][G.discardCount[G.whoseTurn]]);
  if (G.discard[G.whoseTurn][G.discardCount[G.whoseTurn - 1]] == silver)
    printf("Test Passed\n");
  else {
    printf("Test Failed\n");
    passed = 1;
  }
  if (passed == 0)
    printf("1 test passed buyCard\n\n");
  else
    printf("1 test failed buyCard\n\n");
  return 0;
}
