/*
Given a Binary Search Tree.
Your task is to complete the function which will return the Kth largest 
element without doing any modification in Binary Search Tree.

Example 1:
Input:
      4
    /   \
   2     9
k = 2 
Output: 4
*/

class Solution
{
    public:
     void inorder(Node*root ,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int>ans;
       inorder(root,ans);
       int count =ans.size();
       //1 st largest is arr[1]
       //so kth largest is arr[n-k]
       if(K<=count)
       return ans[count-K];
       return -1;
    }
};
