/*
Given two Binary Trees. Check whether they are Isomorphic or not.
Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips,
i.e. by swapping left and right children of several nodes.
Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if(root1==NULL || root2==NULL)
        {
            return false;
        }
        if(root1->data != root2->data) 
        {
            return false;
        }
        if(isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left)) 
        {
        return true;
        }
        if(isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))
        {
            return true;
        }
        return false;
    }
};
