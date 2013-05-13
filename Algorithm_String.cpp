#ifndef  _ALGORITHM_STRING_CPP_
#define  _ALGORITHM_STRING_CPP_

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>

using namespace std;

//-----------------------------------------------------------------------
/*
    k. Given a array of characters, reverse all the words in the array. ( Take space, period, comma,
    question mark and exclamation mark as the separator)

*/
void reveseWords(char *sentence)
{
    printf("original sentence: %s\n", sentence);

    char *revesedSen;
    int i, j, start, len;
    start = 0;
    len = strlen(sentence);
    revesedSen = new char[len+1];
    *revesedSen = '\0';

    int c;
    char *word;

    for (i = 0; i <= len; ++i) {
        if (sentence[i] == ' ' || sentence[i] == '.' ||
            sentence[i] == ',' || sentence[i] == '?' ||
            sentence[i] == '!' || sentence[i] == '\0') {

                word = new char[(i-start)+1];
                c = 0;
                for (j = i-1; j >= start; --j) {
                    word[c++] = sentence[j];
                }
                word[c] = '\0';

                strcat(revesedSen, word);

                switch(sentence[i]) {
                    case ' ': strcat(revesedSen, " "); break;
                    case '?': strcat(revesedSen, "?"); break;
                    case '.': strcat(revesedSen, "."); break;
                    case ',': strcat(revesedSen, ","); break;
                    case '!': strcat(revesedSen, "!"); break;
                }

                start = i+1;
                delete word;
            }
    }
    printf("reversed sentence: %s\n", revesedSen);
}

#endif

//-------------------------------------------------------------------------------------

int main()
{
    reveseWords("The quick brown fox jumped over lazy old dog.");
    return 0;
}
