/*
N people from 1 to N are standing in the queue at a movie ticket counter.
It is a weird counter, as it distributes tickets to the first K people and then the last K people and again first K people and so on, once a person gets a ticket moves out of the queue. 
The task is to find the last person to get the ticket.

Example 1
Input:
N = 9
K = 3
Output:
6
Explanation:
Starting queue will like {1, 2, 3, 4, 5, 6, 7, 8, 9}. 
After the first distribution queue will look like {4, 5, 6, 7, 8, 9}. 
And after the second distribution queue will look like {4, 5, 6}.
The last person to get the ticket will be 6.
*/
class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int i=1;
        int j=N;
        
        while(true){
          if(i+K<j)i+=K;
          else return j;
          
          if(j-K>i) j-=K;
          else return i;
        }
        
        return 1e9+7;
    }
};
