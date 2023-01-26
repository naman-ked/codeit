/*
Given a Binary Tree of size N , where each node can have positive or negative values. 
Convert this to a tree where value of each node will be the sum of the values of all the nodes in left and right sub trees of the original tree. 
The values of leaf nodes are changed to 0.Note: You have to modify the given tree in-place.

Example 1:
Input:
             10
          /      \
        -2        6
       /   \     /  \
      8    -4   7    5
Output:
            20
          /     \
        4        12
       /  \     /  \
     0     0   0    0
Explanation:
           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
*/
class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    void toSumTree(Node *node){
        ToSumTree(node);
    }
    
    int ToSumTree(Node *node)
    {
        // Your code here
        if(node==NULL) return 0;
        int temp =node->data;
        if(node->left==NULL and node->right==NULL){
            node->data=0;
            return temp;
        }
        else{
            node->data=ToSumTree(node->left)+ToSumTree(node->right);
            return temp+node->data;
        }
    }
};
