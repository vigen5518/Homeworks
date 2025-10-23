int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // While the current element is not in the correct place
        while (arr[i] != i + 1) {
            int correctIndex = arr[i] - 1;
            swap(arr[i], arr[correctIndex]);
            swaps++;
        }
    }

    return swaps;
}
