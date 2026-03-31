#include <iostream>
using namespace std;

bool staircaseSearch(int matrix[4][4], int n, int key) {
    int i = 0, j = n - 1;  // Start at top-right corner

    while (i < n && j >= 0) {
        if (matrix[i][j] == key) {
            cout << "Key " << key << " found at position (" << i << ", " << j << ")" << endl;
            return true;
        }
        else if (matrix[i][j] > key) {
            j--; // Move left
        }
        else {
            i++; // Move down
        }
    }
    cout << "Key " << key << " not found." << endl;
    return false;
}

int main() {
    int matrix[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    staircaseSearch(matrix, 4, key);

    return 0;
}
