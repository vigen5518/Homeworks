// Array Manipulation function here
#include <vector>
using namespace std;


long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0);

    for (auto &q : queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];
        arr[a] += k;
        arr[b + 1] -= k;
    }

    long maxVal = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += arr[i];
        maxVal = max(maxVal, current);
    }
    return maxVal;
}
