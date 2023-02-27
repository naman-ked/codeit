/*
Given a linked list and a number k. You have to reverse first part of linked list with k nodes and the second part with n-k nodes.

Example 1:
Input: 1 -> 2 -> 3 -> 4 -> 5
k = 2
Output: 2 -> 1 -> 5 -> 4 -> 3
Explanation: As k = 2 , so the first part 2 nodes: 1 -> 2 and the second part with 3 nodes:3 -> 4 -> 5. 
Now after reversing the first part: 2 -> 1 and the second part: 5 -> 4 -> 3.So the output is: 2 -> 1 -> 5 -> 4 -> 3
*/

class Solution
{
public:
    Node *reverse(Node *head, int k)
    {
        // code here
        Node* cur = head;
        Node* prev = NULL;
        Node* next = NULL;
        int c = 0;
        while(cur != NULL && c < k){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            c++;
        }
        if(next == NULL)  return prev;
        head->next = reverse(next, INT_MAX);
        return prev;
    }
};
