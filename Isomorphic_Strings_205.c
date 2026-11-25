#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool historyCompare(const char *stringToBeValidated, const char *historySource)
{
    char * const charHistory = calloc(128lu, 1lu);
    if (!charHistory){
        fprintf(stderr, "Heap memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    const size_t testLength = strlen(stringToBeValidated);

    bool result = true;

    for (size_t i = 0lu;i < testLength;++i){
        if (!*(charHistory + *(stringToBeValidated + i)))
            *(charHistory + *(stringToBeValidated + i)) = *(historySource + i);
        else if (*(charHistory + *(stringToBeValidated + i)) && *(charHistory + *(stringToBeValidated + i)) != *(historySource + i)){
            result = false;
            break;
        }
    }

    free(charHistory);


    return result;
}

bool isIsomorphic(char* s, char* t) 
{
    return historyCompare(s, t) && historyCompare(t, s);
}
