
/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int mis= 0;                        
        int it = 0;                        
        for(int i=1 ; i<=arr.back();i++){   
            if(arr[it]==i){
                it++;
            }else{
                mis++;
            }
            if(mis==k){
                return i;
            }
        }
        return arr.back()+k-mis;
    }
};
