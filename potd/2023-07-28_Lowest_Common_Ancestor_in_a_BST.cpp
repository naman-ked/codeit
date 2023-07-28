/*
Given a Binary Search Tree (with all values unique) and two node values n1 and n2 (n1!=n2). Find the Lowest Common Ancestors of the two nodes in the BST.
Example 1:
Input:
              5
            /   \
          4      6
         /        \
        3          7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
*/
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(root==NULL) return NULL;
            if(n1>root->data && n2>root->data){
                return LCA(root->right,n1,n2);
            }
            if(n1<root->data && n2<root->data){
                return LCA(root->left,n1,n2);
            }
            if((n1<root->data && n2>root->data)  || (n1>root->data && n2<root->data)){
                return root;
            }
            if(root->data==n1 || root->data==n2){
                return root;
            }
            return NULL;
        }
};
