/*
Given a Binary Search Tree and a target value.
You have to find the node whose data is equal to target and return the sum of all descendant node's data which are vertically below the target node.
Initially you are at the root node.
Note: If target node is not present in bst then return -1.

Example 1:
                    25
                   /   \
                 20     35
                /  \    /  \
              15    22 30  45
                        \
                        32

Target = 35
Output: 32
Explanation: Vertically below 35 is 32.
*/
class Solution{
public:
    
    Node *temp=NULL;
    long long int sum=0;
    //searching for the node
    void search(Node *root,int target){
        if(root==NULL)return;
        else if((root->data)==target)temp=root;
        else if((root->data)>target)search(root->left,target);
        else search(root->right,target);
    }
    //sum of all descendant node's data
    void solve(Node *root, int j){
        if(j==0) sum+= root->data;
        if(root->left)solve(root->left, j - 1);
        if(root->right)solve(root->right, j + 1);
    }
    
    long long int verticallyDownBST(Node *root,int target){
        // Code here
        search(root,target);
        if(temp==NULL) return -1;
        solve(temp, 0);
        return sum - temp->data;
    }
};
