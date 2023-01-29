/*
You are given two numbers A and B, Now you are asked to form two lists, first list contains all the numbers which are divisible by A and less than equal to B,
second list contains all the numbers which are divisors of B and greater than equals to A.Finally you need to print common elements of both the lists in ascending order.
Example 1:
Input:
A=1000000000
B=2000000000

Output:
1000000000 2000000000
*/

class Solution{
	public:
	vector<long long> allNumbers(long long A,long long B)
	{
 		vector<long long> v1;
    long long x=A;
    while(A<=B){
           if(B%A==0) v1.push_back(A);
           A+=x;
       }
    	return v1;	
	}
};
