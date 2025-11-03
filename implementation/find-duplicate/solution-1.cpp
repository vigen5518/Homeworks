#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findDuplicate(const vector<int>& arr) {
    unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(num)) return num;
        seen.insert(num);
    }
    return -1;
}

int main() {
    vector<int> arr = {3, 1, 4, 2, 5, 3}; 
    cout << "Duplicate number is: " << findDuplicate(arr) << endl;
    return 0;
}
