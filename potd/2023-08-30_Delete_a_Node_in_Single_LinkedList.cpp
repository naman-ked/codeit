/*
Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:
Input: 1 -> 3 -> 4 
       x = 3
Output: 1 -> 3
Explanation: After deleting the node at 3rd position (1-base indexing), the linked list is as 1 -> 3. 

Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node* deleteNode(Node *head,int x)
{
    //Your code here
    Node *current=head;
    Node *prev=head;
    if(x==1) return head->next;
    while(x>1){
        prev=current;
        current=current->next;
        x--;
    }
    prev->next=current->next;
    return head;
}
