/*
There is a rectangular path for a Train to travel consisting of n rows and m columns. 
The train will start from one of the grid's cells and it will be given a command in the form of string s consisting of characters L, R, D, U.
Find if it is possible to travel the train inside the grid only.
Note: If the train is at position (i,j) on taking 'L' it goes to (i,j-1), on taking 'R' it goes to (i,j+1), on taking 'D' it goes to (i-1,j), on taking 'U' it goes to (i+1,j).
Example 1:
Input: 
n = 1, m = 1 s = "R"
Output: 0
Explaination: There is only one cell(1,1). So train can only start from (1,1). On taking right(R) train moves to (1,2), which is out of grid.
Therefore there is no cell from where train can start and remain inside the grid after tracing the route. 
*/

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int maxl = 0, maxr = 0, maxu = 0, maxd = 0, c1 = 0, c2 = 0;
        for(int i = 0;i < s.length();i++){
            if(s[i] == 'L') c1--;
            else if(s[i] == 'R') c1++;
            else if(s[i] == 'U') c2++;
            else c2--;
            if(c1 >= 0) maxr = max(c1, maxr);
            else maxl = min(c1, maxl);
            if(c2 >= 0) maxu = max(c2, maxu);
            else maxd = min(c2, maxd);
        }
        if(maxr-maxl < m && maxu-maxd < n) return 1;
        return 0;    
    }
};
