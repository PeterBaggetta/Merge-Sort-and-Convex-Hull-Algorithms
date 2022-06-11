/* Pietro Baggetta
 * 1092160
 * Feburary 14, 2022
 * CIS3490 Assignment 2
 * Question 2.2 Solution
*/

#include "myHeader.h"

/* find the shortest path between the two inputted points from the user */
void shortestPath (double hull[][2], double S1[2], double S2[2], int size) {

    int index1, index2, i, j1, j2;
    double x, y, lengthLeft = 0.0, lengthRight = 0.0;
    double tempLeft[100][2], tempRight[100][2];

    for (int i = 0; i < size; i++) {
        if (hull[i][0] == S1[0] && hull[i][1] == S1[1]) {
            index1 = i;
        }
        if (hull[i][0] == S2[0] && hull[i][1] == S2[1]) {
            index2 = i;
        }
    }

    /* check going left on convex hull */
    i = index1;
    j1 = 0;
    while (i != index2) {
        /* iterate through the hull and store the points until index 2 (s2) is reached */
        tempLeft[j1][0] = hull[i][0];
        tempLeft[j1][1] = hull[i][1];

        /* if the index is at the bottom of the array, move to the top and continue searching */
        if (i == 0) {
            i = size;
        } else {
            i--;
        }
        j1++;
    }

    /* calculate the distance between all the points */
    for (int k = 0; k < j1 - 1; k++) {
        for (int l = k + 1; l < j1; l++) {
            x = pow ((tempLeft[k][0] - tempLeft[l][0]), 2);
            y = pow ((tempLeft[k][1] - tempLeft[l][1]), 2);
            lengthLeft += sqrt (x + y);
        }
    }
    
    /* check going right on convex hull */
    i = index1;
    j2 = 0;
    while (i != index2) {
        /* iterate through the hull and store the points until index 2 (s2) is reached */
        tempRight[j2][0] = hull[i][0];
        tempRight[j2][1] = hull[i][1];
        
        /* if the index is at the top of the array, move to the bottom and continue searching */
        if (i == size) {
            i = 0;
        } else {
            i++;
        }
        j2++;
    }

    /* calculate the distance between all the points */
    for (int k = 0; k < j2 - 1; k++) {
        for (int l = k + 1; l < j2; l++) {
            x = pow ((tempRight[k][0] - tempRight[l][0]), 2);
            y = pow ((tempRight[k][1] - tempRight[l][1]), 2);
            lengthRight += sqrt (x + y);
        }
    }
    
    printf ("=============================================================\n");
    /* print the number of points along the shortest path of the two points */

    /* if the left path has a shorter distance print out the relative numbers */
    if (lengthLeft < lengthRight) {
        printf ("The number of points on the shortest path: %d\n", j1);
        printf ("The distance: %lf\n", lengthLeft);

        /* print the points that make up the shortest path */
        for (int k = 0; k < j1; k++) {
            printf ("(%7.2lf, %7.2lf)\n", tempLeft[k][0], tempLeft[k][1]);
        }
        printf ("(%7.2lf, %7.2lf)\n", hull[index2][0], hull[index2][1]);
    }

    /* if the right path has a shorter distance print out the relative numbers */
    if (lengthLeft > lengthRight) {
        printf ("The number of points on the shortest path: %d\n", j2);
        printf ("The distance: %lf\n", lengthRight);

        /* print the points that make up the shortest path */
        for (int k = 0; k < j2; k++) {
            printf ("(%7.2lf, %7.2lf)\n", tempRight[k][0], tempRight[k][1]);
        }
        printf ("(%7.2lf, %7.2lf)\n", hull[index2][0], hull[index2][1]);
    }
}

/* This function checks the orientation of the points given to this function from the loop */
int orientation (double p[], double q[], double r[]) {
    int value = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);

    /* colinear points */
    if (value == 0) {
        return 0;
    }
    /* clockwise or counterclockwise */
    return (value > 0) ? 1 : 2;
}

/* This function gets the smaller of the two values */
double min (double a, double b) {
    return (a > b) ? b : a;
}

/* This function gets the larger of the two values */
double max (double a, double b) {
    return (a < b) ? b : a;
}

/* this function checks if the point is on the line or not */
bool onLine (double p[], double q[], double r[]) {
    return (q[0] <= max (p[0], r[0]) && q[0] >= min (p[0], r[0]) && q[1] <= max (p[1], r[1]) && q[1] >= min (p[1], r[1]));
}

void P22 (double S[][2], int size) {

    /* timer for P22 */
    clock_t startTime = clock();
    double totalTime = 0.0;

    /* variables used in code */
    int i = 0, j = 0, l = 0, x = 0, q;
    double hull[30000][2];

    /* find the leftmost point */
    for (i = 1; i < size; i++) {
        if (S[i][0] < S[l][0]) {
            l = i;
        } else if (S[i][0] == S[l][0] && S[i][1] < S[l][1]) {
            /* for handling colinear points (same x position but different y) */
            l = i;
        }
    }
    int p = l;

    do {
        /* place the point onto the hull */
        hull[x][0] = S[p][0];
        hull[x][1] = S[p][1];
        x++;

        q = (p + 1) % size;

        for (i = 0; i < size; i++) {
            /* if i is more counterclockwise than the current point q, update q */
            if (orientation (S[p], S[i], S[q]) == 2) {
                q = i;
            }
            /* handling for colinear points, if q is in the middle then update q */
            if (p != i && orientation (S[p], S[i], S[q]) == 0 && onLine (S[p], S[q], S[i])) {
                q = i;
            }
        }

        /* q is most counterclockwise point from p so update it and repeat */
        p = q;
    } while (p != l);

    /* print the convex hull */
    printf ("Points on the convex hull with divide and conquer are found to be:\n");
    for (i = 0; i < x; i++) {
        printf("(%7.2lf, %7.2lf)\n", hull[i][0], hull[i][1]);
    }

    /* compute and print the total time */
    clock_t endTime = clock();
    totalTime += (double)(endTime - startTime) / CLOCKS_PER_SEC;  /* calculate the time in seconds */
    printf ("\nTime for computing hull: %f seconds\n\n", totalTime);

    /* ask the user for the two points to find the shortest path between
       along the convex hull */
    double S1[2], S2[2];
    printf ("Finding the shortest path between 2 points. Hit 'Enter' key after each number is inserted.");
    printf ("\nNo spaces allowed in number. MUST ENTER A END ZERO.");
    printf ("\nPOINTS TO BE ENTERED MUST BE IN THE CONVEX HULL, the convex hull is printed before to reference points.");
    printf ("\nIf the point is not on the convex hull, the program will throw an fault and exit.\n");
    
    /* get the s1 x coordinate */
    printf ("\nEnter s1's x coordinate: ");
    scanf ("%lf", &S1[0]);

    /* get the s1 y coordinate */
    printf ("Enter s1's y coordinate: ");
    scanf ("%lf", &S1[1]);

    /* get the s2 x coordinate */
    printf ("Enter s2's x coordinate: ");
    scanf ("%lf", &S2[0]);

    /* get the s2 y coordinate */
    printf ("Enter s2's y coordinate: ");
    scanf ("%lf", &S2[1]);

    /* compute shortest path */
    shortestPath (hull, S1, S2, x);
}
