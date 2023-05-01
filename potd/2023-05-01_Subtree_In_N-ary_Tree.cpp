/*
Given root of a n-ary tree find the number of duplicate subtree in the n-ary tree.
Two trees are duplicate if they have the same structure with the same node values.
*/
class Solution{
public:
    unordered_map<string, int> map;
    string solve(Node* root) {
        if(root == nullptr) {
            return "";
        }
        string returnValue = to_string(root->data);
        for(auto child : root->children) {
            returnValue += "#" + solve(child);
        }
        map[returnValue]++;
        return returnValue;
    }
    
    int duplicateSubtreeNaryTree(Node *root){
        // Code here
        solve(root);
        int ans = 0;
        for(auto& val : map) {
            if(val.second > 1) {
                ans++;
            }
        }
        return ans;
    }
};

/*
Idea : 
In order to count the number of duplicate subtrees, we can count the occurences of each subtree in the tree.
Now, let me break the task into 3 steps:

1. Traverse over all the subtrees.
2. Store each subtree in the map.
3. Iterate over the map values and check if (value>1). In that case out answer will increament.

But How to store the values in the map🤔?? we can do one thing to implement this, we can represent each subtree as a string. And then store that string in map.
The idea is pretty simple:
 1. Traverse the whole N-array tree using recursion.
 2. While traversing, make a string for representing  current root subtree.
 */
