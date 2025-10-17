#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1); 
        for (int j = 1; j < i; ++j) {
            row[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(row); 
    }
    return res;
}

int main() {
    int numRows;
    cin >> numRows;
    vector<vector<int>> triangle = generate(numRows);
    cout << "[";
    for (size_t i = 0; i < triangle.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < triangle[i].size(); ++j) {
            cout << triangle[i][j];
            if (j + 1 < triangle[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < triangle.size()) cout << ",";
    }
    cout << "]";
    return 0;
}
