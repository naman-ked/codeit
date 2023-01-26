/*
You are given N elements, you can remove any two elements from the list, note their sum, and add the sum to the list. 
Repeat these steps while there is more than a single element in the list. The task is to minimize the sum of these chosen sums.

Example 1:
Input:
N = 4
arr[] = {1, 4, 7, 10}
Output:
39
*/

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>>p;
        for(int i=0;i<N;i++)p.push(arr[i]);
        if(N==1)  return 0;
        int sum=0,a=0,b=0;
        while (!p.empty()) {
            a=p.top();
            p.pop();
            if(!p.empty()){
                b=p.top();
                p.pop();
            }
            else b=0;
            sum+=a+b;
            if(p.size()>0)p.push(a+b);
        }
        return sum;
    }
};
