/*
  Author:     Donald Elliott (inputChar and *inputString)
  Class:      CS362-400
  Assignment: Quiz 2
  Due Date:   10/22/17
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Generating random ASCII characters between 'space' and '~'. Those coincide
// with the decimal numbers 32 through 126. So take the difference (which is 94),
// generate a random int from that plus 32 to get us back to the base number of
// 32 to ensure we are getting the characters we want.
char inputChar() {
    // TODO: rewrite this function
    // Generate random number from 0 to 93, then add 32 to it
    char stateCheck = rand() % 94 + 32;
    return stateCheck;
}

char *inputString() {
    // TODO: rewrite this function
    char randomChar;
    int i = 0;
    // Create an array with 6 slots to account for the word
    // 'reset' plus a null terminator
    static char mainArr[6];
    i = 0;
    while(i < 5) {
      // Constraining the ASCII letters to e-t (cover all letters in 'reset')
      randomChar = ((rand() % 16) + 101);
      // Assign a randomized letter from e to t in mainArr
      // from index 0 to 4. Chose e to t as it contains all the
      // letters we need to make 'reset' and won't take forever
      // to find the phrase for the grading TA. Also tested with
      // the entire uppercase/lowercase alphabet.
      mainArr[i] = randomChar;
      i++;
    }
    // Store null terminator into index 5
    mainArr[5] = '\0';
    // Return the array
    return mainArr;
}

// testme() WAS ALREADY CODED FOR US
// I reformatted some of it to make it easier to read
void testme() {
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1){
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
    if (c == '[' && state == 0)
      state = 1;
    if (c == '(' && state == 1)
      state = 2;
    if (c == '{' && state == 2)
      state = 3;
    if (c == ' ' && state == 3)
      state = 4;
    if (c == 'a' && state == 4)
      state = 5;
    if (c == 'x' && state == 5)
      state = 6;
    if (c == '}' && state == 6)
      state = 7;
    if (c == ')' && state == 7)
      state = 8;
    if (c == ']' && state == 8)
      state = 9;
    if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9) {
      printf("error ");
      exit(200);
    }
  }
}

// main() WAS ALREADY CODED FOR US
int main(int argc, char *argv[]) {
    srand(time(NULL));
    testme();
    return 0;
}
