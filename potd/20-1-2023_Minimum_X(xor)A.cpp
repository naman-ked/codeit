 /*
 Given two integers A and B, the task is to find an integer X such that (X XOR A) is minimum possible
 and the count of set bit in X is equal to the count of set bits in B.

Example 1:

Input: 
A = 3, B = 5
Output: 3
Explanation:
Binary(A) = Binary(3) = 011
Binary(B) = Binary(5) = 101
The XOR will be minimum when x = 3
i.e. (3 XOR 3) = 0 and the number
of set bits in 3 is equal
to the number of set bits in 5.
 */
 
 class Solution {
  public:
    
    int countSetBits(int n)
    {
        // base case
        if (n == 0) return 0;
        else return 1 + countSetBits(n & (n - 1));
    }
        
    int minVal(int a, int b) {
        // code here
        vector<int> c;
        int m=countSetBits(b);
        int n=countSetBits(a);
        int count=max(n,m)-min(n,m);
        if(m<n){
           int p=0,c=a;
            while(count>0){
                if(c%2!=0){
                    int mask = 1 << p;
                    a=a^mask;
                    count--;
                }
                c=c/2;
                p++;
            }
        }
        else if(m>n){
            int p=0,c=a;
            while(count>0){
                if(c%2==0){
                    int mask = 1 << p;
                    a=a^mask;
                    count--;
                }
                c=c/2;
                p++;
            }
        }
        return a;
    }
};
