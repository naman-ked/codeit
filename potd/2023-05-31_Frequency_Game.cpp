/*
Given an array A of size N. The elements of the array consist of positive integers.
You have to find the largest element with minimum frequency.

Example 1:
Input: 
5
2 2 5 50 1
Output: 50
Explanation : All elements are having frequency 1 except 2. 50 is the maximum element with minimum frequency.

Example 2:
Input:
4
3 3 5 5
Output: 5
Explanation: Both 3 and 5 have the same frequency, so 5 should be returned.
*/

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        
        // counting frequency
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        // find highest element with min frequency
        int h1=n+1,h2=0;
        for(int i=0;i<n;i++){
            if(m[arr[i]]<h1){
                h1=m[arr[i]];
                h2=arr[i];
            }
            else if(m[arr[i]]==h1){
                if(arr[i]>h2)h2=arr[i];
            }
        }
        return h2;
    }
};
