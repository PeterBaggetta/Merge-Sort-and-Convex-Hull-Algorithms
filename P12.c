/* Pietro Baggetta
 * 1092160
 * Feburary 14, 2022
 * CIS3490 Assignment 2
 * Question 1.2 Solution
*/

#include "myHeader.h"

/* merge all parts of the array back together so it is all sorted */
int mergeAll (int A[], int temp[], int left, int mid, int right) {
    int i = 0, j = 0, k = 0;
    int inversion_count = 0;

    i = left;   /* for left subarray */
    j = mid;    /* for right subarray */
    k = left;   /* for merged subarray */

    while ((i <= mid - 1) && (j <= right)) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];

            inversion_count = inversion_count + (mid + i);
        }
    }

    /* copy rest of elements of left array to temp (if any) */
    while (j <= right) {
        temp[k++] = A[j++];
    }

    /* put merged elements back into original array */
    for (i = left; i <= right; i++) {
        A[i] = temp[i];
    }

    return inversion_count;
}

/* main part of the recurrisve algorithm which splits the array into halves */
int mergeSort (int A[], int temp[], int left, int right) {
    int mid, inversion_count = 0;

    if (right > left) {
        /* divide array into two parts */
        mid = (right + left) / 2;

        /* keep iterating through and counter number of inversions */
        inversion_count += mergeSort (A, temp, left, mid);
        inversion_count += mergeSort (A, temp, mid + 1, right);

        /* merge the two parts */
        inversion_count += mergeAll (A, temp, left, mid + 1, right);
    }
    return inversion_count;
}

void P12 (int A[], int counter) {

    /* variables used */
    int temp[counter];
    int left = 0, right = counter - 1, inversions = 0;

    /* sent to the merge sort algorithm */
    inversions = mergeSort (A, temp, left, right);

    printf ("Total Inversions = %d\n", inversions);
}
