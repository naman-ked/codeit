/*
Given a rectangle of dimensions L x B find the minimum number (N) of identical squares of maximum side 
that can be cut out from that rectangle so that no residue remains in the rectangle. Also find the dimension K of that square.

Example 1:
Input: L = 2, B = 4
Output: N = 2, K = 2
Explaination: 2 squares of 2x2 dimension.

Example 2:
Input: L = 6, B = 3
Output: N = 2, K = 3
Explaintion: 2 squares of 3x3 dimension. 

*/
class Solution{
public:
    
    long long int Gcd(long long int a,long long int b){
        if(a%b==0) return b;
        else return Gcd(b,a%b);
    }
    
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
        long long int x=Gcd(L,B);
        long long int b=(L*B)/(x*x);
        return {b,x};
    }
};
