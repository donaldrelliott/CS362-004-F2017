/*
  Author:   Donald Elliott
  Class:    CS362-400
  Testing:  smithy
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
  int passed = 0, failedTests = 0, totalTests = 0, thisPlayer = 0;
  int position = 0, c1 = 0, c2 = 0, c3 = 0, bonus = 0;
  int k[10] = { smithy, adventurer, village, mine, minion,
              steward, treasure_map, council_room, feast, gardens };
  struct gameState G, test;
  initializeGame(2, k, 1000, &G);

  printf("\nTesting smithy card\n");

  memcpy(&test, &G, sizeof(struct gameState));
  totalTests++;
  printf("Hand count: %d\n", test.handCount[thisPlayer]);
  printf("Expected: %d\n", G.handCount[thisPlayer]);
  printf("Deck count: %d\n", test.deckCount[thisPlayer]);
  printf("Expected: %d\n", G.deckCount[thisPlayer]);
  if (test.handCount[thisPlayer] == G.handCount[thisPlayer] && test.deckCount[thisPlayer] == G.deckCount[thisPlayer])
    printf("Hand/deck have correct count | Test Passed\n\n");
  else {
    printf("Hand/deck don't have correct count | Test Failed\n\n");
    passed = 1;
    failedTests++;
  }
  cardEffect(smithy, c1, c2, c3, &test, position, &bonus);
  printf("Check hand/deck count.\n");
  totalTests++;
  int cards = 3;

  printf("Hand count: %d\n", test.handCount[thisPlayer]);
  printf("Expected: %d\n", G.handCount[thisPlayer] + cards - 1);
  printf("Deck count: %d\n", test.deckCount[thisPlayer]);
  printf("Expected: %d\n", G.deckCount[thisPlayer] - cards);
  if (test.handCount[thisPlayer] == G.handCount[thisPlayer] + cards - 1 && test.deckCount[thisPlayer] == G.deckCount[thisPlayer] - cards)
    printf("Hand/deck have correct count | Test Passed\n");
  else {
    printf("Hand/deck don't have expected count | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  if (passed == 0)
    printf("\n%d out of 2 tests passed\n\n", totalTests - failedTests);
  else
    printf("\n%d out of 2 tests failed\n\n", failedTests);
  return 0;
}
