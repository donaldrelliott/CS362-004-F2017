/*
  Author:   Donald Elliott
  Class:    CS362-400
  Testing:  isGameOver()
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

int main() {
  int success = 0;
  int failedTests = 0, totalTests = 0;
  int i, j = 0;
  int k[10] = {smithy, adventurer, village, mine, minion, steward, treasure_map, baron, feast, gardens};
  struct gameState G;
  initializeGame(2, k, 100, &G);
  printf("\nTesting isGameOver()\n");
  totalTests++;
  if (isGameOver(&G) == 0){
    printf("Game state at start of game should be 0.\n");
    printf("Game state tested: %d | Passed\n\n", isGameOver(&G));
  }
  else {
    printf("Tested game state is wrong. | Failed\n");
    success = 1;
    failedTests++;
  }
  int provinces = G.supplyCount[province];
  int estates = G.supplyCount[estate];
  totalTests++;
  printf("Province size: %d. Game is not over.\n", G.supplyCount[province]);
  printf("Estate size: %d. Game is not over.\n", G.supplyCount[estate]);
  if (isGameOver(&G) == 0)
    printf("Test Passed\n\n");
  else {
    printf("Test Failed\n\n");
    success = 1;
    failedTests++;
  }
  G.supplyCount[province] = 0;
  G.supplyCount[estate] = 0;
  totalTests++;
  printf("Province size: %d. Game is over.\n", G.supplyCount[province]);
  printf("Estate size: %d. Game is over.\n", G.supplyCount[estate]);
  if (isGameOver(&G) == 1)
    printf("Test Passed\n\n");
  else {
    printf("Test Failed\n\n");
    success = 1;
    failedTests++;
  }
  G.supplyCount[province] = provinces;
  G.supplyCount[estate] = estates;
  for (i = 0; i < 25; i++) {
    if(G.supplyCount[i] != 0)
      j++;
  }
  totalTests++;
  if (j >= 22) {
    printf("Supplies aren't empty - %d.\n", j);
    printf("Game is not over.\n");
    if (isGameOver(&G) == 0)
      printf("Test Passed\n\n");
    else {
      printf("Test Failed\n\n");
      success = 1;
      failedTests++;
    }
  }
  j = 0;
  for (i = 0; i < 3; i++) {
    G.supplyCount[i] = 0;
    j++;
  }
  totalTests++;
  if (j <= 3) {
    printf("Supplies were emptied - %d.\n", j);
    printf("Game is over.\n");
    if (isGameOver(&G) == 1)
      printf("Test Passed\n");
    else {
      printf("Test Failed\n");
      success = 1;
      failedTests++;
    }
  }
  if (success == 0)
    printf("\n%d OF 5 TESTS PASSED.\n\n", totalTests - failedTests);
  else
    printf("\n%d OF 5 TESTS FAILED.\n\n", failedTests);
  return 0;
}
