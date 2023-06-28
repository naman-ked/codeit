/*
Given a binary tree, find its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example 1:
Input:
 root  -->     1
             /   \
            3      2
           /
          4           
Output: 3
Explanation:
Maximum depth is between nodes 1 and 4, which is 3.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of the tree)
*/
class Solution{
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        // Your code here
        int l=0,r=0;
        if(root->left!=NULL) l=maxDepth(root->left);
        if(root->right!=NULL) r=maxDepth(root->right);
        return max(l,r)+1;
    }
};
