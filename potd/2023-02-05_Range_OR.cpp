/*
You are given an intege N. Find the bitwise OR of all integers from 1 to N.
Input: 
N = 3
Output:
3
Explanation:
1 | 2 | 3 = 3

*/
class Solution{
	public:
	int rangeOR(int n)
	{
		//code here
		if(n==0) return 0;
		int bitCount = log2(n) + 1;
		 return pow(2, bitCount) - 1;
		
	}
};
