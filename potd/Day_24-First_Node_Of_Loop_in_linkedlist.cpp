/*
Find the first node of loop in linked list

Given a singly linked list of N nodes. Find the first node of the loop if the linked list has a loop. 
If a loop is present return the node data of the first node of the loop else return -1.
*/

class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        if(head==NULL) return -1;
        Node *slow=head->next;
        if(slow==NULL) return -1;
        Node *fast=head->next->next;
        
        while(fast!=slow){
            slow=slow->next;
            if(slow==NULL) return -1;
            else fast=fast->next->next;
            if(fast==NULL) return -1;
        }
        
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        
        return head->data;
    }
};
