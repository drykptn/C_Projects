#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_WORDS 500
#define WORD_LENGTH 50

int getAndFilterWord(char * w); //returns 0 if the piece of input does not contain any letter to add into the array; 1 if it does.
int getInputs(char words[][WORD_LENGTH]);
char* myLower(char* c);
void addWord(char * w, char words[MAX_NUM_WORDS][WORD_LENGTH],               int occur [MAX_NUM_WORDS], int * word_count);

void sortWords(char words[MAX_NUM_WORDS][WORD_LENGTH], int occur[MAX_NUM_WORDS], int word_count);
void cleanArray(char* w);

int main(int argc, char const *argv[])
{
    int i;
    int size = 0;
    int word_count = 0;
    int occur[MAX_NUM_WORDS];
    char w[] = "De2rYa";
    char words[MAX_NUM_WORDS][WORD_LENGTH];	
    size = getInputs(words);

    for (i = 0; i < size; ++i){
            getAndFilterWord(words[i]);
            printf("%s\n", words[i]);
    }
    i = 2;
    //for (i = 0; i < 4; ++i){
            addWord(words[i], words, occur, &word_count);
            printf("%d\n", occur[i]);
    //}



    return 0;
}

int getInputs(char words[][WORD_LENGTH] ){
    int i;			 /* for loop             */
    int line;
    int count;
    line = 1;		 /* condition for loop   */		
    count = 0;       /* size of string array */
    /* line is equal 1 as long as it continue, else stop*/
    for ( i = 0; line ; i++ )
    {
        scanf("%s", words[i]);
        count++;
        /* if word is equals "end", stop the loop */
        if( strcmp(words[i], "end") == 0 ){
            words[i][0] = '\0';
            line = 0;
        }
    }   
    return count;
}

int getAndFilterWord(char * w){
    int i;
    /* Take the char array and send to tolower function */
    for (i = 0; i < strlen(w); ++i)
            w[i] = tolower(w[i]);
    /* clean the array from the unnecessary characters */
    cleanArray(w);
    /* if array still have numbers, punctuation marks etc., so return 0*/
    for (i = 0; i < strlen(w); ++i)
            if(w[i] < 'a' || w[i] > 'z')
                    return 0;
    /* else */
    return 1;
}
/* This function removes everything else than letters */
void cleanArray(char* w){
    int i;
    int j;
    for (i = 0; i < strlen(w); ++i)
    {
        /* if any of element is not a letter, remove it*/
        if(w[i] < 'a' || w[i] > 'z'){
            for (j = i; j < strlen(w); ++j)
                w[j] = w[j+1];
            }
    }		
}

void addWord(char * w, char words[MAX_NUM_WORDS][WORD_LENGTH],                 
	         int occur [MAX_NUM_WORDS], int * word_count)
{
    int i;
    int j = 0;
    if( getAndFilterWord(w) == 1 ){
        
    }
}

