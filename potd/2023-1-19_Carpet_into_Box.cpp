/*
There is a carpet of a size a*b [length * breadth].
You are given a box of size c*d. The task is, one has to fit the carpet in the box in a minimum number of moves. 
In one move, you can either decrease the length or the breadth of the carpet by half (floor value of its half).
Note: One can even turn the carpet by 90 degrees any number of times, wont be counted as a move.

Example 1:
Input:
A = 8, B = 13
C = 6, D = 10
Output:
Minimum number of moves: 1
Explanation:
Fold the carpet by breadth, 13/2 i.e. 6, so now carpet is 6*8 and can fit fine.
*/

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int a=A,b=B,c=C,d=D;
        int cnt1=0;
        while(a>c){ a= a/2; cnt1++; }
        while(b>d){ b= b/2; cnt1++; }
        int cnt2=0;
        a=A,b=B;
        while(b>c){ b= b/2; cnt2++; }
        while(a>d){ a= a/2; cnt2++; }
        return min(cnt1,cnt2);
    }
};
