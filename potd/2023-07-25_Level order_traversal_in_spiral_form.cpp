/*
Given a binary tree and the task is to find the spiral order traversal of the tree.
Spiral order Traversal mean: Starting from level 0 for root node, 
for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right. 
Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
*/
vector<int> findSpiral(Node *root)
{
    vector<int> sol;
    Node* tmp=root;
    queue<Node*> q;
    q.push(root);
    int lvl=0;
    while(!q.empty()){
        vector<int> b;
        int c=q.size();
        while(c>0){
            Node* a=q.front();
            q.pop();
            if(a->left!=NULL)  q.push(a->left);
            if(a->right!=NULL) q.push(a->right);
            b.push_back(a->data);
            c--;
            }
        if(lvl%2==0){
            for(int i=b.size()-1;i>=0;i--)sol.push_back(b[i]);
        }
        else{
            for(int i=0;i<b.size();i++) sol.push_back(b[i]);
        }
        lvl++;
    }
    return sol;
}
