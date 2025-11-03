#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(const vector<int>& arr) {
    size_t n = arr.size();
    unsigned int expected = (n - 1) * n / 2;
    unsigned int actual = 0;
    for (int num : arr) actual += num;
    return actual - expected;
}

int main() {
    vector<int> arr = {1, 4, 3, 2, 5, 3}; 
    cout << "Duplicate number is: " << findDuplicate(arr) << endl;
    return 0;
}
