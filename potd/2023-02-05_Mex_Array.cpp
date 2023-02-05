/*
You are given an array A of length N.Let us define an array B as Bi = mex(A1,A2,..,Ai)for 1<=i<=N
mex of an array refers to the smallest missing non-negative integer of the array. For example mex of {0,1,2,2} is 3 and mex of {1,2,3,4,5} is 0.
You are allowed to rearrange the elements of A. Find the lexicographically smallest array B which can be obtained

Example 1:
Input: 
N = 3,
A = { 0,1,2 }
Output:
0 0 3
Explanation:
When A = { 1,2,0 }, we get the best possible result.

Example 2
Input:
N = 3,
A = { 0, 0, 1}
Output:
0 2 2
Explanation:
When A = { 1,0,0 }, we get the best pssible result.
*/

class Solution{
	public:
	vector<int> mexArray(int n,int a[])
	{
		//code here
		vector<int> arr;
		for(int i=0;i<n;i++){
		    arr.push_back(a[i]);
		}
		sort(arr.begin(), arr.end());
		int c=0;
		for(int i=0;i<n;i++){
		    if(arr[i]==0) c++;
		    else break;
		}
		vector<int> final(n,0);
		for(int i=0;i<n-c;i++){
		    final[i]=arr[i+c];
		}
		
		vector<int> res;
		set<int> my_set;
		
		for(int i=0;i<n-c;i++){
		  my_set.insert(final[i]);
		  res.push_back(0);
		}
		my_set.insert(0);
		int x;
		int max_element = *my_set.rbegin();
		int min_element =  *(--my_set.rend());
		for(int i=min_element+1;i<=max_element+1;i++){
		        if(my_set.find(i)==my_set.end()){ x=i;
		            break;
		        }
		}
		
		for(int i=0;i<c;i++)res.push_back(x);
		return res;
		
	}
};
