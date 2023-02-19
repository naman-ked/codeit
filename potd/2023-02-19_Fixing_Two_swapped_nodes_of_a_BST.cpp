/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1

Example 2:

Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: By swapping nodes 11 and 10, the BST can be fixed.
*/

class Solution {
  public:
    Node* temp1;
    Node* temp2;
    
     void inorderTraversal(Node* root, vector<int>& v) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left, v);
        v.push_back(root->data);
        inorderTraversal(root->right, v);
    }
    
     void updateTree(Node* root, vector<int>& v, int& index) {
        if (root == NULL) {
            return;
        }
        updateTree(root->left, v, index);
        root->data = v[index++];
        updateTree(root->right, v, index);
    }
    
    struct Node *correctBST(struct Node *root) {
        // code here
         vector<int> v;
        inorderTraversal(root, v);
        sort(v.begin(), v.end());
        int index = 0;
        updateTree(root, v, index);

        return root;
    }
};
