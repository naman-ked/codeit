/*
Given two numbers A and B, you are asked to color all the numbers which are divisible by A in red and color all the numbers divisible by B in blue(starting form zero),
if there is a number which is divisible by both A and B then you can color it either red or blue. 
Now consider only those numbers which are colored and arrange them in ascending order and discard all other numbers,
You are asked to color the numbers such that the size of the longest subarray in which color of all the numbers are same is minimised, 
print the size of longest such subarray.
*/
Example 1:
Input:
A=2
B=4

Output:
1
*/
class Solution{
	public:
	int longestSubarray(int A,int B)
	{
		//code here
		if(A==B) return 1;
		int a=min(A,B);
		int b=max(A,B);
		
		if(b%a==0) return (b/a)-1;
		int diff=b%a;
		int ans=b/a;
		if(a%diff) ans++;
		
		return ans;
		
	}
};
