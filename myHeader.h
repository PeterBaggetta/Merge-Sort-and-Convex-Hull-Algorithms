/* Pietro Baggetta
 * 1092160
 * Feburary 14, 2022
 * CIS3490 Assignment 2
 * Header File
*/

#ifndef _MYHEADER_H
#define _MYHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

void P11(int A[], int counter);

void P12(int A[], int counter);
int mergeAll (int A[], int temp[], int left, int mid, int right);
int mergeSort (int A[], int temp[], int left, int right);

void P21 (double S[][2], int size);
void P22 (double S[][2], int size);


#endif
