/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Example 1:
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
*/

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        if(!head1 || !head2) 
            return -1;
        Node *a=head1;
        Node *b=head2;

        while(a!=b)    {
            a=a==NULL?head2:a->next;
            b=b==NULL?head1:b->next;
        }
        if(a==NULL) return -1;
        return a->data;
    }
};
