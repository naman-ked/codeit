/*
You are given an array a and you need to generate an array b. You are allowed to apply only one type of operation on the array a, any number of times.
In one operation you can swap ai, ai+1 if ai+ai+1 is even.
Array b should be generated after applying the above operation any number of times on array a and array b should be lexicographically
the largest among all arrays that can be generated from array a, after applying the above operation any number of times.

Example 1:

Input:
N=3
a[]={1,3,5}
Output:
5,3,1
Explanation: [1,3,5],[1,5,3],[3,1,5],[3,5,1],[5,1,3] and [5,3,1] are all possible values of array b while the last one is  lexicographically largest.
*/

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int prev=0;
            for(int i=1;i<n;i++)
            {
                if(a[i]%2==a[i-1]%2)// odd odd or even even
                    continue;
                else // previous group was a group that can be sorted
                {
                     sort(a.begin()+prev,a.begin()+i,greater<int>{});
                     prev=i; // new group starting here
                }
            }
            sort(a.begin()+prev,a.end(),greater<int>{});
            return a;
        }
};
