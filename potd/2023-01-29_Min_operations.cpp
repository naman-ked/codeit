/*
Given two numbers a and b. In one operation you can pick any non negative integer x and either of a or b. 
Now if you picked a then replace a with a&x else if you picked b then replace b with b&x.
Return the minimum number of operation required to make a and b equal.
Note: Here & represents bitwise AND operation.

Example 1:
Input:
a = 5, b = 12
Output: 2
Explanantion:In first operation replace a = a&4 = 4after that replace b = b&6 = 4Hence both are same after applying twooperations.
*/

class Solution {
  public:
    int solve(int a, int b) {
        if(a==b) return 0;
        int c=a&b;
        if(c==a || c==b) return 1;
        else return 2;
    }
};
