#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "calc.h"


typedef struct dvalstack {
    double val;
    struct dvalstack* next;
    } dvalstack;

dvalstack* valuestack; // file local stack

/* push: push f onto value stack */
void push(double f) {
    dvalstack* new  = calloc(1,sizeof(dvalstack));
    if (new != NULL) {
        new->val = f;
        new->next = valuestack;
        valuestack = new;
        return;
        }
    else
        fprintf(stderr, "error: can't push on stack\n");
    return;
    }

/* pop: pop and return top value from stack */
double  pop(void) {
    if (valuestack == NULL) {
        fprintf(stderr, "error: stack empty\n");
        return 0.0;
        }
    double res = valuestack->val;
    dvalstack* toDel = valuestack;
    valuestack = valuestack->next;
    free(toDel);
    return res;
    }

/* cleanStack: free all elements on stack */
bool cleanStack(void) {
    dvalstack* runner;
    while((runner = valuestack) != NULL) {
        valuestack = valuestack->next;
        free(runner);
        }
    //fprintf(stderr, "info: done, cleaning stack\n");
    return true;
}

