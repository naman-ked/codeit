/*
Given the base (in units) of a right-angled isoceles traingle, find the maximum number of 2X2 squares that can fit in the triangle with given base.

Example 1:
Input: 8
Output: 6
*/


class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
        //code here
        if(base%2!=0) base--;
        long long int max_sq=(base/2)*(base/2);
        long long int cut_sq=(base/2);
        return (max_sq-cut_sq)/2;
    }
};
