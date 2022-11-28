/**
Find out the maximum sub-array of non negative numbers from an array.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
a = [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.
If no such subarray is present return "-1"

Example 1:

Input:
n = 3
a[] = {1, 2, 3}
Output: 1 2 3
Explanation: In the given array every
element is non-negative.
Example 2:

Input:
n = 2
a[] = {-1, 2}
Output: 2
Explanation: The only subarray [2] is
the answer.
**/


class Solution{
public:
	vector<int> findSubarray(int nums[], int n) {
	    // code here
	    vector<int> res;
	    int start=0;
	    int end=0;
	    int global=0,sum=0;
	    int global_start=0,global_end=0;
	    for(int i=0;i<n;i++){
	        if(nums[i]>=0)sum=sum+nums[i];
	        else{
	           if(sum>global) 
	           {
	              
	               global=sum;
	               global_start=start;
	               global_end=i;
	           }
	           else if(sum==global){
	            if((end-start)<(global_end-global_start))
	            {
	               global_start=start;
	               global_end=end;
	            }
	           }
	           start=i+1;
	           sum=0;
	        }    
	    }
	    if(sum>global){
	          global_start=start;
	           global_end=n;
	    }
	    for(int i=global_start;i<global_end;i++){
	        res.push_back(nums[i]);
	    }
	    if(res.size()==0) return {-1};
	    return res;
	}
};
