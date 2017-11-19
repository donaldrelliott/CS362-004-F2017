/*
  Author:   Donald Elliott
  Class:    CS362-400
  Testing:  village
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
  int passed = 0, failedTests = 0, tests = 0, p1 = 0;
  int position = 0, c1 = 0, c2 = 0, c3 = 0, bonus = 0;
  int cards = 1;
  int k[10] = { smithy, adventurer, village, mine, minion, steward, treasure_map, council_room, feast, gardens };
  struct gameState G, test;
  initializeGame(2, k, 100, &G);

  printf("\nTesting village card\n");
  memcpy(&test, &G, sizeof(struct gameState));
  tests++;
  printf("Hand count: %d\n", test.handCount[p1]);
  printf("Expected: %d\n", G.handCount[p1]);
  printf("Deck count: %d\n", test.deckCount[p1]);
  printf("Expected: %d\n", G.deckCount[p1]);
  if (test.handCount[p1] == G.handCount[p1] && test.deckCount[p1] == G.deckCount[p1])
    printf("Hand and deck have expected count | Test Passed\n");
  else {
    printf("Hand and deck do not have expected count | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  tests++;
  printf("\nAction count: %d\n", test.numActions);
  printf("Expected: %d\n", G.numActions);
  if (test.numActions == G.numActions)
    printf("Action count has expected acount | Test Passed\n");
  else {
    printf("Action count doesn't have expected acount | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  cardEffect(village, c1, c2, c3, &test, position, &bonus);
  printf("\nChecking hand/deck count after playing village card.\n");
  tests++;
  printf("Actual hand count: %d\n", test.handCount[p1]);
  printf("Expected: %d\n", G.handCount[p1] + cards - 1);
  printf("Actual deck count: %d\n", test.deckCount[p1]);
  printf("expected: %d\n", G.deckCount[p1] - cards);
  if (test.handCount[p1] == G.handCount[p1] + cards - 1 && test.deckCount[p1] == G.deckCount[p1] - cards)
    printf("Hand/deck have correct count | Test Passed\n");
  else {
    printf("Hand/deck don't have correct count | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  printf("\nChecking player action count after playing village card.\n");
  tests++;
  printf("Current player action count: %d\n", test.numActions);
  printf("Expected: %d\n", G.numActions + 2);
  if (test.numActions == G.numActions + 2)
    printf("Action count has correct count | Test Passed\n");
  else {
    printf("Action count doesn't have correct count | Test Failed\n");
    passed = 1;
    failedTests++;
  }

  if (passed == 0)
    printf("\n%d out of %d tests passed\n\n", tests - failedTests, tests);
  else
    printf("\n%d out of %d tests passed\n\n", tests - failedTests, tests);
  return 0;
}
