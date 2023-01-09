/*
Samwell laid out N bowls in a straight line and put a few marbles randomly in each bowl, 
ith bowl has A[i] marbles. A bowl can never have more than 9 marbles at a time. A bowl can have zero marbles. 
Now Samwells friend adds one more marble to the last bowl, after this addition all the bowls must still be aligned with the rules mentioned above.
Adding a marble follows the same rules as of addition with carryover. You are given the initial list of the number of marbles in each bowl 
find the position of the bowl which was last modified. It is guaranteed that there is at least one bowl which has at least one space left.

Note: Consider one-based indexing.

Input:
N = 4
A[] = {3, 1, 4, 5}
Output: 
4
Explanation: 
The last bowl has 5 marbels, we can just 
add the marbel here.
Example 2:

Input:
N = 3
A[] = {1, 9, 9}
Output: 
1
*/
class Solution {
  public:
    int solve(int N, vector<int> A) {
        // code here
        int i=N-1;
        while(A[i]==9)i--;
        return i+1;
    }
};
