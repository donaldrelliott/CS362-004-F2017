/*
  Author:   Donald Elliott
  Class:    CS362-400
  Testing:  fullDeckCount()
*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
  printf("\nTesting fullDeckCount()\n");
  int testCount = 0;
  int failCount = 0;
  struct gameState G;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
              remodel, smithy, village, baron, great_hall};
  initializeGame(2, k, 100, &G);

  // Setup empty deck test
  int h1[0];
  int d1[0];
  int td1[0];
  memcpy(G.hand[0], h1, 0);
  memcpy(G.deck[0], d1, 0);
  memcpy(G.discard[0], td1, 0);
  G.handCount[0] = 0;
  G.deckCount[0] = 0;
  G.discardCount[0] = 0;
  printf("Testing for an empty deck.");
  int result = fullDeckCount(0, copper, &G);
  if (result == 0) {
    printf(" Passed\n");
    testCount++;
  }
  else {
    printf("Failed\n");
    printf("Found %d instead of 0\n", result);
    testCount++;
    failCount++;
  }

  //Setup next 3 tests for coppers, silvers, and gold
  int h2[5] = {copper, silver, gold, silver, copper};
  memcpy(G.hand[0], h2, 5 * sizeof(int));
  G.handCount[0] = 5;
  int d2[7] = {copper, silver, copper, copper, gold, copper, copper};
  memcpy(G.deck[0], d2, 7 * sizeof(int));
  G.deckCount[0] = 7;
  int td2[3] = {copper, silver, copper};
  memcpy(G.discard[0], td2, 3 * sizeof(int));
  G.discardCount[0] = 3;

  //Silver test
  printf("Testing for 4 silvers in deck.");
  result = fullDeckCount(0, silver, &G);
  if (result == 4) {
    printf(" Passed\n");
    testCount++;
  }
  else {
    printf("Failed.\n");
    printf("Found %d instead of 4\n", result);
    testCount++;
    failCount++;
  }

  //Copper test
  printf("Testing for 9 coppers in deck.");
  result = fullDeckCount(0, copper, &G);
  if (result == 9) {
    printf(" Passed\n");
    testCount++;
  }
  else {
    printf("Failed.\n");
    printf("Found %d instead of 9\n", result);
    testCount++;
    failCount++;
  }

  //Gold test
  printf("Testing for 2 golds in deck.");
  result = fullDeckCount(0, gold, &G);
  if (result == 2) {
    printf(" Passed\n");
    testCount++;
  }
  else {
    printf("Failed.\n");
    printf("Found %d instead of 2\n", result);
    testCount++;
    failCount++;
  }

  // Output what passed or failed.
  if (failCount == 0)
    printf("4 OF 4 TESTS PASSED.\n");
  else
    printf("%d OF 4 TESTS PASSED.\n", testCount - failCount);
  return 0;
}
