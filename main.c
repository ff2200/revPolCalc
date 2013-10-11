#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include "calc.h"

#define MAXOP 100

/* reverse Polish calculator */
int main(int argc, const char* argv[]) {
    int type;
    double op2;
    char s[MAXOP];
    
    double lastResult = 0.0;


    while ((type = getop(s)) != EOF) {
        switch(type) {
            case LASTRESULT:
                push(lastResult);
                break;
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    fprintf(stderr, "error: zero divisor\n");
                break;
            case '\n' :
                lastResult = pop();
                printf("\t%.8g\n", lastResult);
                break;
            default:
                fprintf(stderr, "error: unkown command %s\n", s);
                break;
            }
        }
    return 0;
    }




