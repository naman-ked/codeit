/*
There is a row of N walls in Geeksland. 
The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year.
Alexa can color each wall with either pink, black, or yellow.
The cost associated with coloring each wall with a particular color is represented by a 2D array colors of size N*3 , 
where colors[i][0], colors[i][1], and colors[i][2] is the cost of painting ith wall with colors pink, black, and yellow respectively.
You need to find the minimum cost to color all the walls such that no two adjacent walls have the same color.

Example 1:

Input:
N = 3
colors[][] = {{14, 2, 11},{11, 14, 5},{14, 3, 10}}
Output:10
Explanation:
Color wall 0 with black. Cost = 2. Color wall 1 with yellow. Cost = 5. Color wall 2 with black. Cost = 3.Total Cost = 2 + 5 + 3 = 10
*/

class Solution{   
public:
    vector<vector<long long int>> v;
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
         for(int i=0;i<N;i++){
           vector<long long int> v1(4,-1);
           v.push_back(v1);
       }
       return color(0,colors,N,0); 
    }
    
    long long int color(int i,vector<vector<int>> &colors,int N,int c){
        if(i==N)    return 0;
        if(v[i][c]!=-1) return v[i][c];
        long long red,blue,green;
        red=blue=green=1e18;
        if(c!=1) red=colors[i][0]+color(i+1,colors,N,1);
        if(c!=2) blue=colors[i][1]+color(i+1,colors,N,2);        
        if(c!=3) green=colors[i][2]+color(i+1,colors,N,3);
        return v[i][c]=min(red,min(blue,green));
    }
};
