/*
Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

Example 1:

Input:
      2
    /   \
   1     3
K(data of x) = 2
Output: 3 
Explanation: 
Inorder traversal : 1 2 3 
Hence, inorder successor of 2 is 3.
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
          if(root==NULL) return root;
        Node* s;
        while(root!=NULL){
            if(root->data>x->data){
                s=root;
                root=root->left;
            }else{
                root=root->right;
            }
        }
        return s;
    }
};
