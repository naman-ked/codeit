/*
You and your friends decide to dine at a restaurant.
The menu offers N dishes with varying prices, and interestingly, each dish is disliked by exactly one of your friends.
Find the minimum amount you need to spend such that all of the friends have something to eat considering that a dish can be shared among multiple people, and any friend who dislikes a dish will not consume it.
In case, it is not possible return "-1", where the prices of the dishes are represented in array prices and the array dislike represents that the i-th dish is disliked by friend dislike[i].
Example 1:
Input:
N = 5
prices[] = {10, 8, 5, 12, 8}
dislike[] = {1, 1, 3, 2, 4}
Output: 13
Explanation: Choose dishes no. 3 and 5 by spending 5 and 8 coins respectively.
*/

class Solution{
public:
    int MinCost(int n, int prices[], int dislike[]){
        //Write Code Here
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            int ind=-1;
            int price=9999999;
            for(int j=0;j<n;j++){
                if(dislike[j]!=i+1){
                    if(prices[j]<price){
                        ind=j;
                        price=prices[j];
                    }
                }
            }
            if(ind==-1) return -1;
            s.insert(ind);
        }
        int res=0;
        for(int a:s){
            res+=prices[a];
        }
        return res;
    }
};
