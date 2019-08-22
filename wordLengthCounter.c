#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define LARGEST_WORD 20

int main()
{
    int wl, c, state, i, counter;
    wl = counter = 0;
    state = OUT;
    int wordLengths[LARGEST_WORD];

    for (i = 1; i <= LARGEST_WORD; ++i)
        wordLengths[i] = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == ',' ) 
        {
            if(wl > 0)
                ++wordLengths[wl];
            wl = 0;
            state = OUT;
        }
        else if (state == OUT) 
        {
            ++wl;
            state = IN;
        }
        else
            ++wl;   
    }

    printf("\n\nLengths of words\n\n");
    for(i = 1; i <= LARGEST_WORD; ++i) {
        printf("%2d: ", i);
        while (counter < wordLengths[i] && wordLengths[i] != 0)
        {
            printf("*");
            ++counter;
        }
         printf("\n");
        counter = 0;
    }
    return 0;
}