/*
Remove duplicate element from sorted Linked List
Given a singly linked list consisting of N nodes. 
The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. The nodes are arranged in a sorted way.

Example 1:
Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 2 ->2 -> 4-> 5, only 2 occurs more than 1 time. So we need to remove it once.
*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
        if (head == NULL) {
            return NULL;
        }
        else if (head->next != NULL && head->data == head->next->data) {
            return removeDuplicates(head->next);
        }
        else {
            head->next = removeDuplicates(head->next);
            return head;
        }
}
