/*
Imagine an imaginary array of length N containing balls. 
Given 2 arrays color and radius of length N each, where color[i] represents the color of the ith ball while radius[i] represents the radius of ith ball. 
If two consecutive balls have the same color and size, both are removed from the array. Geek wants to know the length of the final imaginary array.

Example 1:
Input: N = 3
color[] = {2, 2, 5}
radius[] = {3, 3, 4}
Output:  1
Explanation: First ball and second ball have same color 2 and same radius 3.So,after removing only one ball is left.It could not be removed from the array. 
Hence, the final array has length 1.
*/

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<int> s1;
        stack<int> s2;
        int n=color.size();
        for(int i=0;i<n;i++){
            if(!s1.empty() and s1.top()==color[i] and s2.top()==radius[i]){
                s1.pop();
                s2.pop();
            }
            else{
                s1.push(color[i]);
                s2.push(radius[i]);
            }
        }
        return s1.size();
    }
};
