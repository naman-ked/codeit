/*
Given an array arr of size n, the task is to find the maximum triplet product in the array.

Example 1:
Input:
n = 4
arr[] = {1, 2, 3, 5}
Output: 30
Explanation: 5*3*2 gives 30. This is the maximum possible triplet product in the array.
*/

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	long long largest = LLONG_MIN, slargest = LLONG_MIN, tlargest = LLONG_MIN;
        long long smallest = LLONG_MAX, ssmallest = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long el = arr[i];

            if (el > largest) {
                tlargest = slargest;
                slargest = largest;
                largest = el;
            } else if (el > slargest) {
                tlargest = slargest;
                slargest = el;
            } else if (el > tlargest) {
                tlargest = el;
            }

            if (el < smallest) {
                ssmallest = smallest;
                smallest = el;
            } else if (el < ssmallest) {
                ssmallest = el;
            }
        }

        if (smallest != LLONG_MAX && ssmallest != LLONG_MAX) {
            return max(smallest * ssmallest * largest, largest * slargest * tlargest);
        }

        return largest * slargest * tlargest;
    }
};
