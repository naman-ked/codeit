/*
Given a Binary Search Tree of size N, find the Median of its Node values.
*/

void inorder(struct Node *root,vector<float> &v){
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

float findMedian(struct Node *root)
{
    vector<float> v;
    inorder(root,v);
    int n = v.size();  
    if(n%2==0)
        return ((v[n/2]+v[n/2 - 1])/2);
    return v[n/2];
}
