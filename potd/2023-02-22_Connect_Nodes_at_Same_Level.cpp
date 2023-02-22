/*
Given a binary tree, connect the nodes that are at the same level. The structure of the tree Node contains an addition nextRight pointer for this purpose.
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

       10                          10 ------> NULL
      / \                       /      \
     3   5       =>            3 ------> 5 --------> NULL
    / \     \                 /  \        \
   4   1   2                 4 --> 1 -----> 2 -------> NULL

Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
       3 ------> NULL
     /   \
    1---> 2 -----> NULL
    
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

class Solution{
    public:
    void connect(Node *root)
    {
       // Code Here
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
             int n=q.size();
             int c=0;
             Node* next=NULL;
             while(c<n){
                Node * prev=next;
                next = q.front(); 
                q.pop(); 
                if(next->left)q.push(next->left);
                if(next->right)q.push(next->right);
                if(c!=0) prev->nextRight=next;          
                c++;
            }
        }
    }    
};
