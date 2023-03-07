/*
Given a Binary Tree having positive and negative nodes. Find the maximum sum of a level in the given Binary Tree.

Example 1:
Input :               
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6
Output: 6
Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6
*/  

class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // Your code here
        queue<Node*> q;
        q.push(root);
        int sum=-99999,s=0;
        while(!q.empty()){
            int n=q.size();
            while(n>0){
                Node* t=q.front();
                q.pop();
                s=s+(t->data);
                if(t->left!=NULL)
                q.push(t->left);
                if(t->right!=NULL)
                q.push(t->right);
                n--;
            }
            sum=max(sum,s);
            s=0;
        }
        return sum;
    }
};
