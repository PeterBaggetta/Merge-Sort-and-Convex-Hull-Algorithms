/* Pietro Baggetta
 * 1092160
 * Feburary 14, 2022
 * CIS3490 Assignment 2
 * Main file
*/

#include "myHeader.h"

int main (int argc, char *argv[]) {

    /* variables used in the program */
    double time1 = 0.0, time2 = 0.0, time3 = 0.0, time4 = 0.0;
    int A[50000], counter = 0, counter2 = 0;
    double S[30000][2];

    /* Open the first data file and store it into an array A to be used */
    FILE *file = fopen ("data_A2_Q1.txt", "r");

    while ( (fscanf (file, "%d %d %d %d %d ", &A[counter], &A[counter + 1], &A[counter + 2], &A[counter + 3], &A[counter + 4])) != EOF ) {
        counter += 5;
    }
    fclose (file);

    /* Open the second data file and store it into an array S to be used */
    FILE *file2 = fopen ("data_A2_Q2.txt", "r");

    while ( (fscanf (file2, "%lf   %lf ", &S[counter2][0], &S[counter2][1])) != EOF ) {
        counter2++;
    }

    fclose (file2);

    /*********************************** Question 1 ***********************************/

    printf ("\n--------------- Question 1.1 / P11 ---------------\n\n");

    clock_t start1 = clock();   /* start the timer */

    P11(A, counter);            /* run the program for Q1.1 */

    clock_t end1 = clock();     /* get the end time */
    time1 += (double)(end1 - start1) / CLOCKS_PER_SEC;  /* calculate the time in seconds */
    printf ("Execution Time = %f seconds\n", time1);

    printf ("\n--------------- Question 1.2 / P12 ---------------\n\n");
    clock_t start2 = clock();   /* start the timer */

    P12(A, counter);            /* run the program for Q1.2*/

    clock_t end2 = clock();     /* get the end time */
    time2 += (double)(end2 - start2) / CLOCKS_PER_SEC;  /* calculate the time in seconds */
    printf ("Execution Time = %f seconds\n", time2);

    /*********************************** Question 2 ***********************************/

    printf ("\n--------------- Question 2.1 / P21 ---------------\n\n");
    printf ("A brute force program for finding the shortest path around\n\n");
    clock_t start3 = clock();   /* get the start time */

    P21 (S, counter2);          /* run the program for Q2.1 */

    clock_t end3 = clock();     /* get the end time */
    time3 += (double)(end3 - start3) / CLOCKS_PER_SEC;  /* calculate the time in seconds */
    printf ("Execution Time = %f seconds\n", time3);

    printf ("\n--------------- Question 2.2 / P22 ---------------\n\n");
    printf ("A divide and conquer program for counting inversions\n\n"); 

    P22 (S, counter2);   /* run the program for Q2.2 */

    return 0;
}