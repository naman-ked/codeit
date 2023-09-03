/*
Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

Example 1:
Input :
         1
       /  \
     2      3
    / \    / \
   4   5  6   7    
Output: 1 2 3 4 7
Explanation:
Corners at level 0: 1
Corners at level 1: 2 3
Corners at level 2: 4 7
*/

void printCorner(Node *root)
{
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node*node=q.front();
            q.pop();
            if(i==0||i==n-1) cout<<node->data<<" ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}
