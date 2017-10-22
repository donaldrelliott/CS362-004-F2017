/*
  Author:   Donald Elliott
  Class:    CS362-400
  Testing:  updateCoins()
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"

int main () {
    int i;
    struct gameState G;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                sea_hag, tribute, smithy, council_room};
    int testsFailed = 0;

    int h1[5] = {smithy, minion, smithy, tribute, mine};
    int h2[5] = {copper, copper, copper, copper, copper};
    int h3[5] = {smithy, minion, gold, gold, copper};
    int h4[5] = {gold, minion, embargo, village, mine};
    int h5[5] = {silver, minion, minion, village, embargo};
    int h6[5] = {copper, embargo, embargo, minion, mine};

    initializeGame(2, k, 100, &G);
    G.handCount[0] = 5;
    printf("\nTesting updateCoins()");

    // Testing no coins
    for(i = 0; i < 5; i++)
      G.hand[0][i] = h1[i];
    updateCoins(0, &G, 0);
    printf("\n1. Expected: %d  Reported: %d", 0, G.coins);
    if (G.coins != 0)
      testsFailed++;
    else
      printf(" | Passed");

    // Testing 5 copper
    for(i = 0; i < 5; i++)
      G.hand[0][i] = h2[i];
    updateCoins(0, &G, 0);
    printf("\n2. Expected: %d  Reported: %d", 5, G.coins);
    if (G.coins != 5)
      testsFailed++;
    else
        printf(" | Passed");

    // Testing typical hand
    for(i = 0; i < 5; i++)
      G.hand[0][i] = h3[i];
    updateCoins(0, &G, 0);
    printf("\n3. Expected: %d  Reported: %d", 7, G.coins);
    if (G.coins != 7)
      testsFailed++;
    else
      printf(" | Passed");

    // Testing 1 gold
    for(i = 0; i < 5; i++)
      G.hand[0][i] = h4[i];
    updateCoins(0, &G, 0);
    printf("\n4. Expected: %d  Reported: %d", 3, G.coins);
    if (G.coins != 3)
      testsFailed++;
    else
      printf(" | Passed");

    // Testing 1 silver
    for(i = 0; i < 5; i++)
      G.hand[0][i] = h5[i];
    updateCoins(0, &G, 0);
    printf("\n5. Expected: %d  Reported: %d", 2, G.coins);
    if (G.coins != 2)
      testsFailed++;
    else
      printf(" | Passed");

    // Testing 1 copper
    for(i = 0; i < 5; i++)
      G.hand[0][i] = h6[i];
    updateCoins(0, &G, 0);
    printf("\n6. Expected: %d  Reported: %d", 1, G.coins);
    if (G.coins != 1)
      testsFailed++;
    else
      printf(" | Passed");

    printf("\n%d OF 6 TESTS PASSED\n\n", 6-testsFailed);
    return 0;
}
