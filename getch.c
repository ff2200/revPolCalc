#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct inputBuf {
    int val;
    struct inputBuf* next;
    } inputBuf;

static inputBuf* inputBuffer;

/* getch: the function which actually gets chars! */
int getch(void) {
    if (inputBuffer == NULL)
        return getchar();
    inputBuf* item = inputBuffer;
    inputBuffer = inputBuffer->next;
    int res = item->val;
    free(item);
    return res;
    }

/* ungetch: push character back into input buffer */
void ungetch(int c) {
    inputBuf* new = calloc(1, sizeof(inputBuf));
    if (new == NULL)
        fprintf(stderr, "ungetch: too many character\n");
    else {
        new->val = c;
        new->next = inputBuffer;
        inputBuffer = new;
        }
    }

bool cleanInputBuffer(void) {
    inputBuf* runner;
    while ((runner = inputBuffer) != NULL) {
        inputBuffer = inputBuffer->next;
        free(runner);
        }
    //fprintf(stderr, "info: cleaning input buffer done\n");
    return true;
    }
