#ifndef SCANFS_H
#define SCANFS_H

#include "unit_test.h"
#include "quadratic.h"

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>

#define GetUp "\x1b[1A"
#define Clear "\r\x1b[2K"
#define MAX_SYMBOLS 100
#define inf 3
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[38;2;0;255;0m"
#define CLEAR "\033[0m"

const double delta = 0.0000001;

bool IsZero(double num);
void RussianLanguage();
double get_coef();
int length(double num);
void Input(double *a, double *b, double *c);
void ReplaceLine(const char *text);
void Output(int nRoots, double x1, double x2);

#endif