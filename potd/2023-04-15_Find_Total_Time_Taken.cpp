/*
You are given an array arr of size n, containing the values in between 1 to n & time of size n, containg time in sec,
you are asked to determine the total time taken in order to pick all the array elements from left to right but there is a condition, 
If from left, previous elments are different it takes 1 Sec to pick & if element got repeated then it will take time[arr[i]].

NOTE:
1. It takes 1 sec to move from index i to i+1 (1 <= i < n).
2. 1-based indexing.

Example 1:
Input:
n = 4
arr = {1, 2, 3, 3}
time = {1, 2, 3, 4}
Output: 5
Explanation:
for 1st element(1) = 0 Sec-> total = 0 2nd element(2) = 1 Sec-> total = 1+0=1
    3rd element(3) = 1 Sec-> total = 1+1=2 4th element(3) : here element 3 is repeated so we have to calculate time by time[arr[i]] : 
    time[arr[4]] => time[3] => 3 -> total = 2+3 =5 here you can see 4th element(3) is repeated so time will be not 1 sec & we have to 
    calculate time by this: time[arr[i]],there Index is 4 which means arr[4] gives 3 & then time[3]=3.
*/

class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        // code here
        unordered_set<int> s;
        int res=0;
        s.insert(arr[0]);
        for(int i=1;i<n;i++){
            if(s.find(arr[i])!=s.end())res+=time[arr[i]-1];
            else{
                res++;
                s.insert(arr[i]);
            }
        }
        return res;
    }
};
