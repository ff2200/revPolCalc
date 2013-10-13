#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "calc.h"

#define MAXOP 100

bool testIfInteger(double x, double* intptr);

/* reverse Polish calculator */
int main(int argc, const char* argv[]) {
    int type;
    double op1int = 0;
    double op2int = 0;
    double op1;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
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
            case '%':
                op2 = pop();
                op1 = pop();
                if ((testIfInteger(op1, &op1int) && testIfInteger(op2, &op2int)) && op2int != 0)
                    push((int)op1int % (int)op2int);
                else
                    fprintf(stderr, "error: modulo by zero or operand is not integer\n");
                break;
            case '\n' :
                printf("\t%.8g\n", pop());
                break;
            default:
                fprintf(stderr, "error: unkown command %s\n", s);
                break;
            }
        }
    return 0;
    }

/* testIfInteger: returns true if x is integer, integer part is stored in intptr */
bool testIfInteger(double x, double* intptr) {
    double y;
    if((y = modf(x, intptr)) < 0.0 || y > 0.0)
        // tests with == 0.0 are error prone
        return false;
    return true;
    }


