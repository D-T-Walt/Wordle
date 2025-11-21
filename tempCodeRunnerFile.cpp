/*
 * MatrixManipulation.cpp
 *
 *  Created on: 4 Feb 2025
 *      Author: Diwan1
 */
#include <iostream>

using namespace std;

// Function to add two integers
int addition(int num1, int num2) {
    return num1 + num2;
}

int main1() {
    int row1 = 3, col1 = 3, row2 = 3, col2 = 3, x, y;

    // 2D arrays declared using the stated dimensions
    int matrix1[row1][col1];
    int matrix2[row2][col2];
    int result[row2][col2];

    cout << "Populate Matrix 1\n";
    for (x = 0; x < row1; x++) {
        for (y = 0; y < col1; y++) {
            cout << "Enter the value of [" << x << "][" << y << "]: ";
            cin >> matrix1[x][y];
        }
    }

    cout << "\nPopulate Matrix 2\n";
    for (x = 0; x < row2; x++) {
        for (y = 0; y < col2; y++) {
            cout << "Enter the value of [" << x << "][" << y << "]: ";
            cin >> matrix2[x][y];
        }
    }

    // Display Matrix 1
    cout << "\nMatrix 1\n";
    for (x = 0; x < row1; x++) {
        for (y = 0; y < col1; y++) {
            cout << matrix1[x][y] << "\t";
        }
        cout << endl;
    }

    // Display Matrix 2
    cout << "\n\nMatrix 2\n";
    for (x = 0; x < row2; x++) {
        for (y = 0; y < col2; y++) {
            cout << matrix2[x][y] << "\t";
        }
        cout << endl;
    }

    // Compute and display addition result
    cout << "\n\nAddition Result\n";
    for (x = 0; x < row1; x++) {
        for (y = 0; y < col1; y++) {
            result[x][y] = addition(matrix1[x][y], matrix2[x][y]);
            cout << result[x][y] << "\t";
        }
        cout << endl;
    }

    // Display full addition equation
    cout << "\n\n";
    for (x = 0; x < row1; x++) {
        for (y = 0; y < col1; y++) {
            cout << matrix1[x][y] << "\t";
        }

        if (x == 1) {
            cout << "+\t";
        } else {
            cout << "\t";
        }

        for (y = 0; y < col1; y++) {
            cout << matrix2[x][y] << "\t";
        }

        if (x == 1) {
            cout << "=\t";
        } else {
            cout << "\t";
        }

        for (y = 0; y < col1; y++) {
            cout << result[x][y] << "\t";
        }

        cout << endl;
    }

    cout << "\n\n";

    return 0;
}






