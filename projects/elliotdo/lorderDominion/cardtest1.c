/*
  Author:   Donald Elliott
  Class:    CS362-400
  Testing:  adventurer
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
  int k[10] = { smithy, adventurer, village, mine, minion, steward,
              treasure_map, council_room, feast, gardens };
  char x1[32];
  char x2[32];
  struct gameState G, test;
  initializeGame(2, k, 100, &G);

  printf("\nTesting adventurer card\n\n");

  memcpy(&test, &G, sizeof(struct gameState));
  totalTests++;
  printf("Hand count: %d\n", test.handCount[thisPlayer]);
  printf("Expected: %d\n", G.handCount[thisPlayer]);
  printf("Deck count: %d\n", test.deckCount[thisPlayer]);
  printf("Expected: %d\n", G.deckCount[thisPlayer]);
  if (test.handCount[thisPlayer] == G.handCount[thisPlayer] && test.deckCount[thisPlayer] == G.deckCount[thisPlayer])
    printf("Hand/deck have expected count | Test Passed\n");
  else {
    printf("Hand/deck don't have expected count | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  cardEffect(adventurer, c1, c2, c3, &test, position, &bonus);
  printf("\nPlay adventurer card.\n");
  printf("Check hand/deck count.\n");
  totalTests++;
  int addedCards = 2;
  printf("Hand count: %d\n", test.handCount[thisPlayer]);
  printf("Expected: %d\n", G.handCount[thisPlayer] + addedCards - 1);
  printf("Deck count: %d\n", test.deckCount[thisPlayer]);
  printf("Expected: %d\n", G.deckCount[thisPlayer] - (G.discardCount[thisPlayer] + addedCards));
  if (test.handCount[thisPlayer] == G.handCount[thisPlayer] + addedCards - 1 && test.deckCount[thisPlayer] == G.deckCount[thisPlayer] - (G.discardCount[thisPlayer] + addedCards))
    printf("Hand/deck have correct count | Test Passed\n\n");
  else {
    printf("Hand/deck don't have correct count | Test Failed\n\n");
    passed = 1;
    failedTests++;
  }
  totalTests++;
  int first = G.hand[thisPlayer][G.handCount[thisPlayer]-1];
  int second = G.hand[thisPlayer][G.handCount[thisPlayer]-2];
  cardNumToName(first, x1);
  cardNumToName(second, x2);
  printf("First new card is %s\n", x1);
  printf("Second new card is %s\n", x2);
  if ((first != copper || first != silver || first != gold) && (second != copper || second != silver || second != gold))
    printf("Top two cards are treasure cards | Test Passed\n");
  else {
    printf("Top two cards aren't treasure cards | Test Failed\n");
    passed = 1;
    failedTests++;
  }
  if (passed == 0)
    printf("\n%d/%d tests passed.\n\n", totalTests - failedTests, totalTests);
  else
    printf("\n%d/%d tests passed.\n\n", totalTests - failedTests, totalTests);
  return 0;
}
