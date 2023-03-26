/*
N frogs are positioned at one end of the pond. All frogs want to reach the other end of the pond as soon as possible. 
The pond has some leaves arranged in a straight line. Each frog has the strength to jump exactly K leaves. 
For example, a  frog having strength 2 will visit the leaves 2, 4, 6, ...  etc. while crossing the pond.
Given the strength of each frog and the number of leaves, your task is to find the number of leaves that not be visited by any of the frogs when 
all frogs have reached the other end of the pond. 

Example 1:
Input:
N = 3
leaves = 4
frogs[] = {3, 2, 4} 
Output: 1
Explanation: Leaf 1 will not be visited by any frog.
*/

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int> leave(leaves+1,0);
        for(int i=0;i<N;i++){
            if(frogs[i]<=leaves and leave[frogs[i]]==0){
            for(int j=frogs[i];j<=leaves;j+=frogs[i]){
                leave[j]=1;
            }
            }
        }
        int count=0;
        for(int i=1;i<=leaves;i++){
            if(leave[i]==0)count++;
        }
        return count;
    }
};
