/*
Geek was playing in a playground and suddenly he encountered an array of length n written with positive integers and he wants you to calculate
the minimum jump capacity he should have to reach the far end of the array with the condition that he only jump on Good index.
Any index i is said to be good if at least one of the following conditions is satisfied for that index
arr[i]%2==0
arr[i]%3==0
<Geek could jump to the right any distance from 1 to the value of his jump ability.
So your task is to return an integer representing the minimum jump ability of the Geek that is needed to reach the last index, jumping only on good indexes.

Note : 0 based indexing is used and Geek is initially at index 0 and wants to reach index n-1.Both 0th (n-1)th index are good .
Example 1:
Input : n=4 arr={2,1,3,6}
Output: 2
Explanation:Indexes 0,2,3 are good indexes as they satisfy at least one condition. So we can jump from 0->2->3 so the minimum jump capacity  is 2.

Input :
n=4 arr={2,5,7,9}
Output: 3
Explanation:0 and 3 are the only good indexes in the array so the only option is there is to jump from index 0 to index 3. Hence minimum jump capacity 3.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function minJump() which takes an integer n and an integer array arr[] respectively as input parameters 
and returns an integer representing the minimum jump ability of the Geek that is needed to reach the last index, jumping only on good indexes.

*/

class Solution{
    public:
    int minJump(int n,vector<int> arr)
    {
        int m=0,j=0;
        for(int i=1;i<n;i++){
            if(arr[i]%2==0 or arr[i]%3==0){
                m=max(j+1,m);
                j=0;
            }
            else j++;
        }
        return m;
    }
};
