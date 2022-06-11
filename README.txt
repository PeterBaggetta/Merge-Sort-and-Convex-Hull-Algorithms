Name:   Pietro Baggetta
ID:     1092160
CIS 3490 Assignment 2

To compile:
    - Type 'make all'.

To clean all object files and execuatbles:
    - Type 'make clean'.

To run the program:
    - First make sure the program is compiled with the command 'make all'.
    - Then run the program by typing './main'.

Before starting the program:
    - Ensure that the two text files Data_A2_Q1.txt and Data_A2_Q2.txt are in the same
      directory as the main.c file, or else the program will not be able to execute.
    - The files will be in the same path as main.c on download of this assignment.

Program Files:
    - This program takes in two different sets of data, which it then computes
      different algorithms for each.
    - Data_A2_Q1.txt
        > The file Data_A2_Q1.txt contains a list of 50,000 numbers which are not in 
          any particular order.
        > This file must be configured with 5 coloumns and each number must be separated
          by a single space in between each number, and have an extra space after the last
          number in the row to be read in properly.
          ie. "1804289383 846930886 1681692777 1714636915 1957747793 "
    - Data_A2_Q2.txt
        > The file Data_A2_Q2.txt contains a list of points with decimals which are not in
          any particular order.
        > This file must be configured with 2 coloumns and each number within the file must be
          separated by 3 spaces in between each number, and have an extra space after the last
          number in the row to be read in properly.
          ie. "4580.2   3289.7 "
    - main.c
        > This C program file holds the main function which calls each repective algorithm in order
          which the assignment states.
        > This file will open the Data_A2_Q1.txt and Data_A2_Q2.txt files that are in the same directory
          as the main.c file is in.
        > Each function P11, P12, P21, and P22 will be called consecutively, and once the function
          has finished its algorithm on the respective file, the time taken to execute the function
          will be printed out.
    - P11.c
        > This function will take the data from the file Data_A2_Q1.txt and sort each number within the
          file with a brute force algorithm.
        > This file will also count the number of inversions taken to execute and perform the brute force
          sorting.
        > The algorithm used is merge sort.
    - P12.c
        > This function will take the data from the file Data_A2_Q1.txt and sort each number within the
          file with a divide and conquer algorithm of BIG_THETA(nlogn) and also count the number of inversions
          taken to sort the data.
        > This function is a more improved version of the function P11.c.
    - P21.c
        > This function wll take the data from the file Data_A2_Q2.txt and calculate the convex hull of the 
          given points using brute force.
        > The convex hull will then be outputed to the terminal to show what the shortest path around is for
          the given set of data.
        > The time taken to execute the algorithm will be printed out after the convex hull has finished its
          calculaion.
    - P22.c
        > This function will take the data from the file Data_A2_Q2.txt and calculaion the convex hull of the 
          given points in the file using a recursive divide and conquer method of BIG_THETA(nlogn).
        > The convex hull will then be outputed to the terminal to show what the shortest path around is for
          the given set of data. (Similar to P21.c).
        > The time taken to execute the algorithm will be printed out after the convex hull has finished its
          calculaion.
        > This function will then ask the user of the program to enter two points (s1 and s2) that are on the
          convex hull.
        > Once the two points are entered, the program will then analize and compute what is the shortest path
          around the convex hull to get from point s1 to point s2 is.
        > After the shotest path between the points has been calculated, the function will output the number of
          points taken to reach s2 from s1, as well as its distance and the points taken to reach this conclusion.
        > When entering points to search for the shortest path on the convex hull, it must follow a specific format.
        > The number being entered must have a trailing zero to match the convex hull that is printed out.
          ie. Enter s1's x coordinate: 6163.40
              Enter s1's y coordinate: 6092.80
              Enter s2's x coordinate: 30.80
              Enter s2's y coordinate: 3064.00

For more information about the efficiency class of each algorithm, consult the file design.pdf.

ERRORS IN CODE:
    - Sometimes the code will randomly enter a set of zeros after finding the shortest path between s1 and s2.
    - Ignore the point of zeros as it does not affect the number of points in the shortest path, nor does it
      affect the distance between the paths. (Did not have enough time to debug this in my code.)
