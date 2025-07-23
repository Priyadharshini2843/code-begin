#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Get matrix dimensions
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Dynamically allocate memory for the matrix
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[cols];

    // Input matrix elements
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    // Display original matrix
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Dynamically allocate memory for transpose matrix
    int** transpose = new int*[cols];
    for (int i = 0; i < cols; ++i)
        transpose[i] = new int[rows];

    // Compute transpose
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            transpose[j][i] = matrix[i][j];

    // Display transpose matrix
    cout << "\nTranspose Matrix:\n";
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j)
            cout << transpose[i][j] << " ";
        cout << endl;
    }

    // Deallocate memory for both matrices
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < cols; ++i)
        delete[] transpose[i];
    delete[] transpose;

    return 0;
}