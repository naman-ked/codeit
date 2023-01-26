/*
Given a binary tree. The task is to find the maximum GCD of the siblings of this tree. 
You have to return the value of the node whose two immediate children has the maximum gcd.
If there are multiple such nodes, return the node which has the maximum value.

Siblings: Nodes with the same parent are called siblings.

GCD (Greatest Common Divisor) of two positive integers is the largest positive integer that divides both numbers without a remainder.

Note:
Return 0 if input tree is empty i.e level of tree is -1.
Consider those nodes which have a sibling.
Return 0 if no such pair of siblings found.
 
Example 1:
Input:
              4
            /   \
           5     2
                /  \
               3    1
              /  \
             6   12

Output: 3
Explanation: For the above tree, the maximum
GCD for the siblings is formed for nodes 6 and 12
for the children of node 3.
*/

class Solution
{
public:
    int max_node=0;
    int max_gcd=0;
    
    int Gcd(int a,int b){
        if(a%b==0) return b;
        else return Gcd(b,a%b);
    }
    
    int maxGCD( Node* root)
    {
        //code here
        int gcd;
        if(root==NULL)return 0;
        
        maxGCD(root->left);
        maxGCD(root->right);
        if(root->left==NULL or root->right==NULL){
            gcd=0;
        }
        else gcd= Gcd(root->right->data,root->left->data);
        if(gcd>max_gcd){
            max_gcd=gcd;
            max_node=root->data;
        }
        else if(gcd==max_gcd and gcd>0) max_node=max(max_node,root->data);
        return max_node;
    }
};
