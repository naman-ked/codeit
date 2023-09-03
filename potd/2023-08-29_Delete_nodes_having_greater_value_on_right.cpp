/*
Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. 
(Not just immidiate Right , but entire List on the Right) 

Example 1:
Input: LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. 
So, after deleting them, the linked list would like be 15,11, 6, 3.
*/

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    void reverse(Node *&head) {
        Node *prev = NULL, *next = NULL;
        while (head) {
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        reverse(head);
        Node *curr = head;
        while (curr -> next) {
            if (curr -> data > (curr -> next -> data)) {
                Node *node = curr -> next;
                curr -> next = node -> next;
                delete node;
            } else {
                curr = curr -> next;
            }
        }   
        reverse(head);
        return head;
    }
};
   
