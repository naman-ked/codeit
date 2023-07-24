/*
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8
*/

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       if (root == NULL) return ans;
       queue<Node *> q;
       q.push(root);
       while (!q.empty())
        {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == size - 1)  ans.push_back(temp->data);
            if (temp->left)     q.push(temp->left);
            if (temp->right)    q.push(temp->right);
        }
        }
        return ans;
    }
};
