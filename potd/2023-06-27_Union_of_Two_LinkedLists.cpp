/*
Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists.
This union list should include all the distinct elements only and it should be sorted in ascending order.
Example 1:
Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output:  1 2 3 4 6 8 9
Explaination:  All the distinct numbers from two lists, when sorted forms the list in the output. 
*/

class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int>s;
        Node* curr=head1;
        while(curr){
            s.insert(curr->data);
            curr=curr->next;
        }
        curr=head2;
        while(curr){
            s.insert(curr->data);
            curr=curr->next;
        }
        Node *head= new Node(0);
        curr=head;
        for(auto it : s){
            curr->next=new Node(it);
            curr=curr->next;
        }
        return head->next;
    }
};
