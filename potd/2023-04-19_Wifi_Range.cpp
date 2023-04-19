/*
There are N rooms in a straight line in Geekland State University's hostel, you are given a binary string S of length N
where S[i] = '1' represents that there is a wifi in ith room or S[i] = '0' represents no wifi.
Each wifi has range X i.e. if there is a wifi in ith room then its range will go upto X more rooms on its left as well as right.
You have to find whether students in all rooms can use wifi.

Example 1: 

Input:
N = 3, X = 0
S = "010"
Output: 0
Explanation: 
Since the range(X)=0, So Wifi is only  accessible in second room & 1st & 2nd room have no wifi.
*/

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        int lastEnd = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(i-x > lastEnd) return 0;
                lastEnd = i+x+1;
            }
        }
        return lastEnd >= n;
    }
};
