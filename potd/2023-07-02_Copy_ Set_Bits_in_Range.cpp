/*
Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 31. 
You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.
Note: Range count will be from Right to Left & start from 1.
Example 1:
Input: 
X = 44, Y = 3 
L = 1,  R = 5
Output: 
47
Explaination: 
Binary represenation of 44 and 3 is 101100 and 000011. So in the range 1 to 5 there are two set bits of 3 (1st & 2nd position). 
If those are set in 44 it will become 101111 which is 47.
*/

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        for(int i=l-1;i<r;i++) {
            if(y&1<<i) x=x|1<<i;
        }
        return x;
    }
};
