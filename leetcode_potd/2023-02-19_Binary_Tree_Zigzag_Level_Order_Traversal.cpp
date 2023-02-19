/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        if(root==NULL){
            return {};
        }
        vector<vector<int>> res;
        while(!q.empty()){
            int n=q.size();
            vector<int> t;
            while(n>0){ 
                 TreeNode * temp=q.front();
                 if(temp!=NULL)
                 {
                 t.push_back(temp->val);
                 if(temp->left!=NULL){
                   q.push(temp->left);    
                 }    
                 if(temp->right!=NULL){    
                   q.push(temp->right);
                 }
                 }
                 q.pop();
                 n--;
            }
            res.push_back(t);
        }
        for(int i=0;i<res.size();i++){
            if(i%2!=0){
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
    }
};
