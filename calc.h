#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include <stdbool.h>
#define NUMBER '0'

void push(double);

double pop(void);

bool cleanStack(void);

int getop(char []);

int getch(void);

void ungetch(int);

bool cleanInputBuffer(void);

#endif // CALC_H_INCLUDED
