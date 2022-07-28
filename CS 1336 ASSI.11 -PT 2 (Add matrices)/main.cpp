/*

    This program will generate and store random numbers between 0 to 50 in 2 3x3
    matrices, and use functions to calculate and display the sum of the matrices.


1. Create 2 matrices that will store random numbers between 0 to 50 and a matrix that will store the addition of the matrices.
2. for (Access each 2D array row)  {
        for (Access each 2D array column)  {
            Generate a random number between 0 to 50 and store it in each matrix (separately).
        {
    }
3. Display the elements of each matrix in an arranged format.
4. Calculate the sum of the matrices.
    for (Access each 2D array row)  {
        for (Access each 2D array column)  {
            Store the addition for each accessed matrix element in a new matrix.
        }
    }
5. Display the resulting matrix to the user.

*/


// This program will generate and store random numbers between 0 to 50 in 2 3x3
// matrices, and use functions to calculate and display the sum of the matrices.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

    // Global constants.
const int MAXROWS = 3;  // The number of rows in each 2D matrix.
const int MAXCOLS = 3;  // The number of columns in each 2D matrix.

    // Function for adding the 2 matrices.
void addMatrix(int [][MAXCOLS], int [][MAXCOLS], int [][MAXCOLS]);

    // Function for displaying the resulting matrix after adding the 2 matrices.
void printResult(int [][MAXCOLS],int [][MAXCOLS], int [][MAXCOLS], char);

    // Main function.
int main()
{
        // Declare variables.
    int matrix1[MAXROWS][MAXCOLS];  // First matrix for storing random numbers between 0 to 50.
    int matrix2[MAXROWS][MAXCOLS];  // Second matrix for storing random numbers between 0 to 50.
    int resultMatrix[MAXROWS][MAXCOLS] = {0};  // Matrix for storing the sum of the 2 matrices (in matrix form).

        // Seed the random number.
    srand (time(0));

        // Access each 2D array row.
    for (int row = 0; row < MAXROWS; row++)
    {
            // Access each 2D array column.
        for (int col = 0; col < MAXCOLS; col++)
        {
                // Generate a random number between 0 to 50 and store it in each matrix (separately).
            matrix1[row][col] = rand() % 50;
            matrix2[row][col] = rand() % 50;
        }
    }

        // Prompt for displaying the first matrix to the user.
    cout << "Matrix1 is :" << endl;

        // Access each 2D array row.
    for (int row = 0; row < MAXROWS; row++)
    {
            // Access each 2D array column.
        for (int col = 0; col < MAXCOLS; col++)
        {
                // Display the current accessed 2D array element for the first matrix.
            cout << setw(2) << left << matrix1[row][col] << " ";
        }

            // Go to the next line.
        cout << endl;
    }

        // Prompt for displaying the second matrix to the user.
    cout << endl << "Matrix2 is :" << endl;

        // Access each 2D array row.
    for (int row = 0; row < MAXROWS; row++)
    {
            // Access each 2D array column.
        for (int col = 0; col < MAXCOLS; col++)
        {
                // Display the current accessed 2D array element for the second matrix.
            cout << setw(2) << left << matrix2[row][col] << " ";
        }

            // Go to the next line.
        cout << endl;
    }

        // Call the function for adding the 2 matrices, pass the 2 matrices and the resulting matrix.
    addMatrix(matrix1, matrix2, resultMatrix);

        // Call the Function for displaying the resulting matrix after adding the 2 matrices.
        // Pass the 2 matrices, the resulting matrix and a '+' character.
    printResult(matrix1, matrix2, resultMatrix, '+');


    return 0;
}

    // Function for adding the 2 matrices.
void addMatrix(int matrix1[][MAXCOLS], int matrix2[][MAXCOLS], int resultMatrix[][MAXCOLS])
{
        // Access each 2D array row.
    for (int row = 0; row < MAXROWS; row++)
    {
            // Access each 2D array column.
        for (int col = 0; col < MAXCOLS; col++)
        {
                // Store the addition for each accessed matrix element in a new matrix.
            resultMatrix[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
}

    // Function for displaying the resulting matrix after adding the 2 matrices.
void printResult(int matrix1[][MAXCOLS],int matrix2[][MAXCOLS], int resultMatrix[][MAXCOLS], char plusSymbol)
{
        // Prompt for displaying the resulting matrix to the user.
    cout << endl << "The addition of the matrices is " << endl;

        // Access each 2D array row.
    for (int row = 0; row < MAXROWS; row++)
    {
            // Access each 2D array column.
        for (int col = 0; col < MAXCOLS; col++)
        {
                // Display the corresponding element in the first matrix.
            cout << setw(2) << left << matrix1[row][col] << " ";
        }

            // Print spaces for all rows except the middle(2nd).
        if (row != 1)
            cout << "    ";

            // Print spaces and '+' for the middle row(2nd).
        else
            cout << " " << plusSymbol << "  ";

            // Access each 2D array column.
        for (int col = 0; col < MAXCOLS; col++)
        {
                // Display the corresponding element in the second matrix.
            cout << setw(2) << left << matrix2[row][col] << " ";
        }

            // Print spaces for all rows except the middle(2nd).
        if (row != 1)
            cout << "    ";

            // Print spaces and '=' for the middle row(2nd).
        else
            cout << " =  ";

            // Access each 2D array column.
        for (int col = 0; col < MAXCOLS; col++)
        {
                // Display the corresponding element in the result matrix.
            cout << setw(2) << left << resultMatrix[row][col] << " ";
        }

            // Go to the next line.
        cout << endl;
    }
}

/*

    RUN 1:

Matrix1 is :
25 6  19
2  39 22
47 35 30

Matrix2 is :
31 33 44
3  19 16
48 41 48

The addition of the matrices is
25 6  19     31 33 44     56 39 63
2  39 22  +  3  19 16  =  5  58 38
47 35 30     48 41 48     95 76 78

    ------------------------------------

    RUN 2:

Matrix1 is :
7  26 39
28 44 25
13 33 1

Matrix2 is :
29 41 8
25 39 17
22 9  26

The addition of the matrices is
7  26 39     29 41 8      36 67 47
28 44 25  +  25 39 17  =  53 83 42
13 33 1      22 9  26     35 42 27

    ------------------------------------

    RUN 3:

Matrix1 is :
9  43  1
42 5  22
18 41 17

Matrix2 is :
20 39 21
24 25 30
36 27 10

The addition of the matrices is
9  43 1      20 39 21     29 82 22
42 5  22  +  24 25 30  =  66 30 52
18 41 17     36 27 10     54 68 27

    --------------------------------------

    RUN 4:

Matrix1 is :
42 28 43
49 0  40
29 36 47

Matrix2 is :
7  46 42
36 31 47
9  20 15

The addition of the matrices is
42 28 43     7  46 42     49 74 85
49 0  40  +  36 31 47  =  85 31 87
29 36 47     9  20 15     38 56 62


*/
