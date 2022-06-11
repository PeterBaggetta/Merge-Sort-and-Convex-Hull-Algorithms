/* Pietro Baggetta
 * 1092160
 * Feburary 14, 2022
 * CIS3490 Assignment 2
 * Question 1.1 Solution
*/

#include "myHeader.h"

void P11 (int A[], int counter) {
    
    int i = 0, j = 0, inversions = 0;

    /* compare all items in the array to one another and find the number of inversions */
    for (i = 0; i < counter - 1; i++) {
        for (j = i + 1; j < counter; j++) {
            if (A[i] > A[j]) {
                inversions++;
            }
        }
    }

    printf ("Total Inversions = %d\n", inversions);
}