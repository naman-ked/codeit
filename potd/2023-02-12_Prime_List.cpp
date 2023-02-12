/*
You are given the head of a linked list.
You have to replace all the values of the nodes with the nearest prime number.
If more than one prime number exists at an equal distance, choose the smallest one.

Example 1:
Input:
2 → 6 → 10
Output:
2 → 5 → 11
Explanation: The nearest prime of 2 is 2 itself.The nearest primes of 6 are 5 and 7,since 5 is smaller so, 5 will be chosen.The nearest prime of 10 is 11.
*/

class Solution{
public:

    int nearestPrime(int n,vector<bool> &primes){
        int diff=0;
        while(true){
            if(n-diff>=0 and primes[n-diff]==true)return n-diff;
            if(n+diff<=10007 and primes[n+diff]==true)return n+diff;
            diff++;
        }
    }
    
    Node *primeList(Node *head){
        vector<bool> primes(10007,true);
        primes[0]=false;
        primes[1]=false;
        for(int i=2;i<=10007;i++)
            for(int j=i*2;j<=10007;j+=i)
                primes[j]=false;
        Node* temp=head;
        while(temp!=NULL){
            int x=nearestPrime(temp->val,primes);
            temp->val=x;
            temp=temp->next;
        }        
        return head;        
    }
};
