#include <iostream>
#include <vector>
using namespace std;

int countMagicTriplets(const vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    // Traverse each element as the middle element
    for (int j = 1; j < n - 1; ++j) {
        int left_count = 0;
        int right_count = 0;

        // Count smaller elements on the left of arr[j]
        for (int i = 0; i < j; ++i) {
            if (arr[i] < arr[j]) {
                ++left_count;
            }
        }

        // Count larger elements on the right of arr[j]
        for (int k = j + 1; k < n; ++k) {
            if (arr[k] > arr[j]) {
                ++right_count;
            }
        }

        // Add the number of triplets with arr[j] as the middle element
        count += left_count * right_count;
    }

    return count;
}

int main() {
    vector<int> arr = {3, 4, 7, 7, 11, 3, 9, 6, 8};
    cout << "Number of magic triplets: " << countMagicTriplets(arr) << endl;
    return 0;
}
