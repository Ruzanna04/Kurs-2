#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void fillSpiralMatrix(const vector<vector<int>>& original, vector<vector<int>>& spiral, int n) {
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int numIndex = 0;

   
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            numbers.push_back(original[i][j]);
        }
    }


    sort(numbers.rbegin(), numbers.rend());

    while (top <= bottom && left <= right) {
        
        for (int i = left; i <= right; i++) {
            spiral[top][i] = numbers[numIndex++];
        }
        top++;

     
        for (int i = top; i <= bottom; i++) {
            spiral[i][right] = numbers[numIndex++];
        }
        right--;

     
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                spiral[bottom][i] = numbers[numIndex++];
            }
            bottom--;
        }

      
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                spiral[i][left] = numbers[numIndex++];
            }
            left++;
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> original(n, vector<int>(n));
    vector<vector<int>> spiral(n, vector<int>(n));
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            original[i][j] = rand() % 100 + 1; 
        }
    }


    cout << "Original Matrix:\n";
    for (const auto& row : original) {
        for (int val : row) {
            cout << val << "\t"; 
        }
        cout << endl;
    }


    fillSpiralMatrix(original, spiral, n);

    cout << "\nSpiral Matrix (Descending Order):\n";
    for (const auto& row : spiral) {
        for (int val : row) {
            cout << val << "\t"; 
        }
        cout << endl;
    }

    return 0;
}
