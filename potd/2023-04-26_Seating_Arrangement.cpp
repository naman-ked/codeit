/*
You are given an integer n, denoting the number of people who needs to be seated, and a list of m integers seats,
where 0 represents a vacant seat and 1 represents an already occupied seat.
Find whether all n people can find a seat, provided that no two people can sit next to each other.

Example 1:
Input:
n = 2
m = 7
seats[] = {0, 0, 1, 0, 0, 0, 1}
Output: Yes
Explanation: The two people can sit at index 0 and 4.
*/


class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        for(int i=0;i<m;i++){
            if(n==0) break;
            if(seats[i]==0){
                if(
                    (i==0 and seats[i+1]==0) ||
                    (i==m-1 and seats[i-1]==0) ||
                    (i!=0 and i!=m-1 and seats[i+1]==0 and seats[i-1]==0)
                ){
                    seats[i]=1;n--;
                }   
            }
        }
        return n==0;
    }
};
