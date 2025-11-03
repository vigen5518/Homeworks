# Find duplicate number
There are 2 solutions posted in this folder, depending on the specified parameters.

**Solution 1**

Generic, uses O(n) for time and space:
This method uses [C++ unordered set](https://en.cppreference.com/w/cpp/container/unordered_set.html) to reduce execution time.
After calling the function, it recursively checks if the integer at current index already exists in the set, if so, returns it as the duplicate number and finishes operation, otherwise continues to load the numbers to the set and compare.

**Solution 2**

If the integers are positive and cap at the size of the array (1, ..., n-1), uses O(n) for time and O(1) for space:
This method expects a duplicate number in the array, and uses a mathematical equation to determine the duplicate number, being:
```math
\sum_{k=1}^{n} k - \frac{(n-1)n}{2}
```
