/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
Examples:

Input: root = [4,2,6,1,3]
Output: 1

Input: root = [1,0,48,null,null,12,49]
Output: 1
*/

class Solution {
public:
    vector<int> v;
    void inOrder(TreeNode* root){
        if(root->left)inOrder(root->left);
        v.push_back(root->val);
        if(root->right)inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        int x=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            x=min(x,abs(v[i]-v[i+1]));
        }
        return x;
    }
};
