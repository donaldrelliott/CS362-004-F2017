/*
  Author:   Donald Elliott
  Class:    CS362-400
  Testing:  council_room
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
  int passed = 0, failedTests = 0, totalTests = 0, p1 = 0;
  int p2 = 1;
  int position = 0, c1 = 0, c2 = 0, c3 = 0, bonus = 0;
  int k[10] = { smithy, adventurer, village, mine, minion, steward, treasure_map, council_room, feast, gardens };
  struct gameState G, test;
  initializeGame(2, k, 100, &G);

  printf("Testing council_room card\n");

  memcpy(&test, &G, sizeof(struct gameState));
  totalTests++;
  printf("Hand count: %d\n", test.handCount[p1]);
  printf("Correct: %d\n", G.handCount[p1]);
  printf("Deck count: %d\n", test.deckCount[p1]);
  printf("Correct: %d\n", G.deckCount[p1]);
  if (test.handCount[p1] == G.handCount[p1] && test.deckCount[p1] == G.deckCount[p1])
    printf("Hand/deck have correct count | Test Passed\n");
  else {
    printf("Hand/deck don't have correct count | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  totalTests++;
  printf("\nPlayer buy count is %d\n", test.numBuys);
  printf("Correct: %d\n", G.numBuys);
  if (test.numBuys == G.numBuys)
    printf("Buy count has correct count | Test Passed\n");
  else {
    printf("Buy count doesn't have correct acount | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  cardEffect(council_room, c1, c2, c3, &test, position, &bonus);
  printf("\nHand/deck count after playing council_room card.\n");
  totalTests++;
  int newCards = 5;
  printf("Hand count is %d\n", test.handCount[p1]);
  printf("Correct: %d\n", G.handCount[p1] + newCards - 1);
  printf("Deck count is %d\n", test.deckCount[p1]);
  printf("Correct: %d\n", G.deckCount[p1] - newCards);
  if (test.handCount[p1] == G.handCount[p1] + newCards - 1 && test.deckCount[p1] == G.deckCount[p1] - newCards)
    printf("Hand/deck have correct count | Test Passed\n");
  else {
    printf("Hand/deck don't have correct count | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  totalTests++;
  printf("\nHand count: %d\n", test.handCount[p2]);
  printf("Correct: %d\n", G.handCount[p2] + 1);
  if (test.handCount[p2] == G.handCount[p2] + 1)
    printf("Hand/deck have correct count | Test Passed\n");
  else {
    printf("Hand/deck don't have correct count | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  printf("\nCheck player buy count after council_room is played.\n");
  totalTests++;
  printf("Player buy count: %d\n", test.numBuys);
  printf("Correct: %d\n", G.numBuys + 1);
  if (test.numBuys == G.numBuys + 1)
    printf("Buy count has correct count | Test Passed\n");
  else {
    printf("Buy count doesn't have correct count | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  if (passed == 0)
    printf("\n%d out of 5 tests passed\n\n", totalTests - failedTests);
  else
    printf("\n%d out of 5 tests passed\n\n", totalTests - failedTests);
  return 0;
}
