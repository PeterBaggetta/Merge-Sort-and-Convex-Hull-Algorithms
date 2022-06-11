/* Pietro Baggetta
 * 1092160
 * Feburary 14, 2022
 * CIS3490 Assignment 2
 * Question 2.1 Solution
*/

#include "myHeader.h"

void P21 (double S[][2], int size) {

    /* variables used in program */
    double hull[30000][2];
    int i = 0, j = 0, k = 0, l = 0, index = 0, compare, extremeNum;
    double x1, x2, x3, y1, y2, y3, a, b, c, d;
    bool isCompare, extreme, isSide, onSide, point1, point2;

    extremeNum = 0;

    /* loop through and get a line to compare points to */
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (S[i][0] != S[j][0] && S[i][1] != S[j][0]) {

                /* point 1 and point 2 */
                x1 = S[i][0];
                y1 = S[i][1];
                x2 = S[j][0];
                y2 = S[j][1];

                /* create a, b, c for the current iteraiton */
                a = y2 - y1;
                b = x1 - x2;
                c = (x1 * y2) - (y1 * x2);

                k = 0, compare = 0;
                isCompare = true, extreme = true;

                /* compare the sides and other conditions with point 3 (k) */
                while (k < size && extreme == true) {

                    /* point is not on the line */
                    if ( (k != i) && (k != j) ) {

                        /* point 3 */
                        x3 = S[k][0];
                        y3 = S[k][1];

                        d = (a * x3) + (b * y3) - c;

                        /* keep track of sides */
                        if (isCompare == true) {
                            if (d < 0) {
                                isSide = false;
                            }
                            if (d > 0) {
                                isSide = true;
                            }
                            isCompare = false;
                        }

                        if (d < 0) {
                            onSide = false;
                        } else if (d > 0) {
                            onSide = true;
                        } else {
                            /* if the points are colinear with point 1 and 2 
                               it can still be part of the convex hull */
                            onSide = isSide;
                        }

                        if (onSide != isSide) {
                            extreme = false;
                        } else {
                            compare++;
                        }
                    }
                    k++;
                }

                /* if n-2 points are on the same side with respect to point 1 and 2
                   then point 1 and point 2 are extreme points */
                if (compare == size - 2) {
                    point1 = true;
                    point2 = true;

                    /* check if the extreme points has been found so it is not taken
                       twice into the convex hull */
                    for (l = 0; l < extremeNum + 1; l++) {
                        x3 = hull[l][0];
                        y3 = hull[l][1];

                        /* check if point 1 has been found */
                        if (x1 == x3 && y1 == y3) {
                            point1 = false;
                        }
                        /* check if point 2 has been found */
                        if (x2 == x3 && y2 == y3) {
                            point2 = false;
                        }
                    }

                    /* if point 1 is a new point in the convex hull */
                    if (point1 == true) {
                        hull[extremeNum][0] = S[i][0];
                        hull[extremeNum][1] = S[i][1];
                        extremeNum++;
                    }

                    /* if point 2 is a new point in the convex hull */
                    if (point2 == true) {
                        hull[extremeNum][0] = S[j][0];
                        hull[extremeNum][1] = S[j][1];
                        extremeNum++; 
                    }
                } 
            }
        }
    }

    /* print the convex hull */
    printf ("Points on the convex hull with brute force are found to be:\n");
    for (i = 0; i < extremeNum; i++) {
        printf ("(%7.2lf, %7.2lf)\n", hull[i][0], hull[i][1]);
    }
    
}
