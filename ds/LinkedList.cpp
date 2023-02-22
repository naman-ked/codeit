#include<iostream>
using namespace std;

class node{
public: 
	int data;
	node* next;

 	node(int data){
 		this->data=data;
 		next=NULL;
 	}
};

//-----LinkedList ------//

void insertAthead(node* &head,int data){
    if(head==NULL){
    	head=new node(data);
    	return;
    }

    node *n=new node(data);
    n->next=head;
    head=n;
}

void printLinked(node* head){
  while(head!=NULL){
  	cout<<head->data<<"-->";
  	head=head->next;
  }
  cout<<endl;
}

int main(){
    node *head=NULL;
    insertAthead(head,4);
    insertAthead(head,1);
    insertAthead(head,2);
    insertAthead(head,3);
    
    printLinked(head);
	return 0;
}
