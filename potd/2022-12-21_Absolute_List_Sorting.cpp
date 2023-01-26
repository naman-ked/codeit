/*
Given a linked list of N nodes, sorted in ascending order based on the absolute values of its data,i.e. negative values are considered as positive ones. 
Sort the linked list in ascending order according to the actual values, and consider negative numbers as negative and positive numbers as positive.

Example 1:

Input: 
List: 1, -2, -3, 4, -5
Output: 
List: -5, -3, -2, 1, 4
Explanation: 
Actual sorted order of {1, -2, -3, 4, -5}
is {-5, -3, -2, 1, 4}
*/
class Solution{
    
public:
    Node* sortList(Node* head)
    {
        // Your Code Here
        Node* res=head;
        Node* prev=head;
        head=head->next;
        while(head){
            Node *temp=head->next;
            if(head->data<0){
                prev->next=head->next;
                head->next=res;
                res=head;
            }
            else{
              prev=head;
            } 
            head=temp;
        }
        return res;
    }
};
