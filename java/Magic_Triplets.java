
/* 

Given an array of size n, a triplet (a[i], a[j], a[k]) is called a Magic Triplet if a[i] < a[j] < a[k] and i < j < k.  
Count the number of magic triplets in a given array.
 

Example 1:

Input: arr = [3, 2, 1]
Output: 0
Explanation: There is no magic triplet.

Example 2:

Input: arr = [1, 2, 3, 4]
Output: 4
Explanation: Fours magic triplets are 
(1, 2, 3), (1, 2, 4), (1, 3, 4) and 
(2, 3, 4).
 

Your Task:
You don't need to read or print anything. Your task is to complete the function countTriplets() which takes the array nums[] as input parameter and 
returns the number of magic triplets in the array.

 
Expected Time Complexity: O(N2) 
Expected Space Complexity: O(1)
*/


class Solution{
    public int countTriplets(int[] nums){
        // code here
        int ans=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            int left=0,right=0;
	        // no. smaller than a[i] would be in the left 
	        for(int j=i-1;j>=0;j--){
	            if(nums[i]>nums[j]) left++;
	        }
	         // no. larger than a[i] would be int the right 
	         for(int k=i+1;k<n;k++)
	         {
	             if(nums[i]<nums[k]) right++;
	         }
	         ans+=(left*right);
        }
        return ans;
    }
}
