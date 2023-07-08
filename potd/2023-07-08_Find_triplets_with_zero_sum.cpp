/*
Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 
Note: Return 1, if there is at least one triplet following the condition else return 0.

Example 1:
Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet with sum equal to 0.
*/

class Solution{
  public:
   //Function to find pairs with zero sum.
   bool printPairs(int arr[], int arr_size,int j, int sum)
   {
        unordered_set<int> s;
        for (int i = j; i < arr_size; i++) {
            int temp = sum - arr[i];
            if (s.find(temp) != s.end()) {
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
    }
    
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        for(int i=0;i<n-1;i++){
            if(printPairs(arr,n,i+1,-1 * arr[i])==true) return true;
        }
        return false;
        
    }
};
