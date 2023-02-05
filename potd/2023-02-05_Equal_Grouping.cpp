/*
Let us group integers on the number line. Let's call integers in the range 2^i,2^(i+1)-1] (both ends inclusive) for 0 ≤ i ≤ 30 in the same group.
You are given an array A of N elements. 
In one operation you can select any subarray of even size such that all integers in the subarray belong to the same group and delete that subarray.
After deleting join the remaining subarrays without changing their order. 
Find the minimum size of A which can be obtained after performing some operations on it.

Example 1:
Input: 
N = 4,
A = { 7, 8, 6, 4  }
Output:
2
Explanation: Since 4 and 6 belongs to the same group we can remove them in one step and after that we can't perform any step because 7 and 8 belongs to different groups.

Example 2:
Input:
N = 3,
A = { 1, 7, 2 }
Output:
3
Explanation: No operations can be performed.
*/

class Solution{
	public:
	int evenGrouping(int n,int a[])
	{
		//code here
		int x,y;
		stack<int> s;
		int c=0;
		for(int i=0;i<n;i++){
		    x=floor(log2(a[i]));
		    if(s.empty()) s.push(x);
		    else if(s.top()!=x)s.push(x);
		    else{
		        int j=i+1;
		        
		        while(j<n){
		            y=floor(log2(a[j]));
		            if(x==y) j++;
		            else break;
		        }
		        int z=j-i;
		        i=j-1;
		        if(z%2==0) continue;
		        else s.pop();      
		    }
		}
		return s.size();
	}
};
