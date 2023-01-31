/*
There is a row of N houses, each house can be painted with one of the three colors: red, blue or green. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color. Find the minimum cost to paint all houses.
The cost of painting each house in red, blue or green colour is given in the array r[], g[] and b[] respectively.

Example 1:

Input:
N = 3
r[] = {1, 1, 1}
g[] = {2, 2, 2}
b[] = {3, 3, 3}
Output: 4
Explanation: We can color the houses in RGR manner to incur minimum cost.
We could have obtained a cost of 3 if we coloured all houses red, but we cannot color adjacent houses with the same color.
*/
class Solution{   
public:
    vector<vector<long long int>> v;
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here
       for(int i=0;i<N;i++){
           vector<long long int> v1(4,-1);
           v.push_back(v1);
       }
       return color(0,r,g,b,N,0);
    }
    
    long long int color(int i,int r[], int g[], int b[],int N,int c){
        if(i==N)    return 0;
        if(v[i][c]!=-1) return v[i][c];
        long long red,blue,green;
        red=blue=green=1e18;
        if(c!=1) red=r[i]+color(i+1,r,g,b,N,1);
        if(c!=2) blue=b[i]+color(i+1,r,g,b,N,2);        
        if(c!=3) green=g[i]+color(i+1,r,g,b,N,3);
        return v[i][c]=min(red,min(blue,green));
        }
};
