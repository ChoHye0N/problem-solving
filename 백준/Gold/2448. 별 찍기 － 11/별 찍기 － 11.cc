#include <iostream>
#include <vector>

using namespace std;

void making_triangle(vector<string>& pattern, int row, int col, int size) {
    if (size == 3) {
        pattern[row][col] = '*';
        pattern[row + 1][col - 1] = '*';
        pattern[row + 1][col + 1] = '*';
        pattern[row + 2][col - 2] = '*';
        pattern[row + 2][col - 1] = '*';
        pattern[row + 2][col] = '*';
        pattern[row + 2][col + 1] = '*';
        pattern[row + 2][col + 2] = '*';
        return;
    }

    int half = size / 2;

    // Upper triangle
    making_triangle(pattern, row, col, half);

    // Lower left triangle
    making_triangle(pattern, row + half, col - half, half);

    // Lower right triangle
    making_triangle(pattern, row + half, col + half, half);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n;
    cin >> n;

    int total_rows = n;
    int width = 2 * total_rows - 1;

    vector<string> pattern(total_rows, string(width, ' '));

    making_triangle(pattern, 0, width / 2, total_rows);

    for (size_t i = 0; i < pattern.size() - 1; i++)
            cout << pattern[i] << '\n';
    cout << pattern[pattern.size() - 1];

    return 0;
}