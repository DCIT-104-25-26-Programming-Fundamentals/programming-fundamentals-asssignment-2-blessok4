// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;


void displayMatrix(int matrix[10][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int transpose[10][10],
                     int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int matrixA[10][10], int matrixB[10][10],
                 int result[10][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Part C: Multiply two matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10],
                      int result[10][10],
                      int rowsA, int columnsA,
                      int rowsB, int columnsB) {

    // Initialize the result matrix to zero
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            for (int k = 0; k < columnsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to input a matrix
void inputMatrix(int matrix[10][10], int rows, int columns,
                 string matrixName) {
    cout << "\nEnter values for Matrix " << matrixName << ":\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

int main() {
    // =========================
    // PART A: TRANSPOSE
    // =========================

    int matrix[10][10];
    int transpose[10][10];

    int rows, columns;

    cout << "PART A - TRANSPOSE MATRIX\n";

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    if (rows <= 0 || rows > 10 || columns <= 0 || columns > 10) {
        cout << "Error: Matrix dimensions must be between 1 and 10."
             << endl;
        return 0;
    }

    inputMatrix(matrix, rows, columns, "A");

    transposeMatrix(matrix, transpose, rows, columns);

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, columns);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, columns, rows);


    // =========================
    // PART B: ADD MATRICES
    // =========================

    int matrixA[10][10];
    int matrixB[10][10];
    int sum[10][10];

    int addRows, addColumns;

    cout << "\n\nPART B - ADD TWO MATRICES\n";

    cout << "Enter number of rows: ";
    cin >> addRows;

    cout << "Enter number of columns: ";
    cin >> addColumns;

    if (addRows <= 0 || addRows > 10 ||
        addColumns <= 0 || addColumns > 10) {

        cout << "Error: Matrix dimensions must be between 1 and 10."
             << endl;
        return 0;
    }

    inputMatrix(matrixA, addRows, addColumns, "A");
    inputMatrix(matrixB, addRows, addColumns, "B");

    addMatrices(matrixA, matrixB, sum, addRows, addColumns);

    cout << "\nMatrix A:\n";
    displayMatrix(matrixA, addRows, addColumns);

    cout << "\nMatrix B:\n";
    displayMatrix(matrixB, addRows, addColumns);

    cout << "\nSum of A + B:\n";
    displayMatrix(sum, addRows, addColumns);


    // =========================
    // PART C: MULTIPLY MATRICES
    // =========================

    int multiplyA[10][10];
    int multiplyB[10][10];
    int product[10][10];

    int rowsA, columnsA;
    int rowsB, columnsB;

    cout << "\n\nPART C - MULTIPLY TWO MATRICES\n";

    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;

    cout << "Enter columns for Matrix A: ";
    cin >> columnsA;

    cout << "Enter rows for Matrix B: ";
    cin >> rowsB;

    cout << "Enter columns for Matrix B: ";
    cin >> columnsB;

    if (rowsA <= 0 || rowsA > 10 ||
        columnsA <= 0 || columnsA > 10 ||
        rowsB <= 0 || rowsB > 10 ||
        columnsB <= 0 || columnsB > 10) {

        cout << "Error: Matrix dimensions must be between 1 and 10."
             << endl;
        return 0;
    }

    // Check the multiplication condition
    if (columnsA != rowsB) {
        cout << "Error: Matrix A columns must equal Matrix B rows."
             << endl;
        return 0;
    }

    inputMatrix(multiplyA, rowsA, columnsA, "A");
    inputMatrix(multiplyB, rowsB, columnsB, "B");

    multiplyMatrices(multiplyA, multiplyB, product,
                     rowsA, columnsA, rowsB, columnsB);

    cout << "\nMatrix A:\n";
    displayMatrix(multiplyA, rowsA, columnsA);

    cout << "\nMatrix B:\n";
    displayMatrix(multiplyB, rowsB, columnsB);

    cout << "\nProduct of A x B:\n";
    displayMatrix(product, rowsA, columnsB);

    return 0;
}
