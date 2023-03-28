/*
Geek went to buy some chocolates from a nearby shop with k coins in his pocket.
He found that the shop contains n chocolates which are arranged in sorted order (increasing) of their prices.
Now geek wants to taste costlier chocolates so he decided that he will buy the costliest chocolate (of course among the ones that he can afford) 
till there exists at least one type of chocolate he can afford. You may assume that there is an infinite supply of chocolates in the shop Geek visited.
As you know, Geek is a shy person and hence he will enquire about the prices of the chocolates at most 50 times from the shopkeeper. 
Now, your task is to find the number of chocolates he had enjoyed. 
Note: If you call the Shop.get function more than 50 times it will return -1. Price of chocolates are pairwise distinct.

Example 1:
Input:
3 5 
2 4 6

Output:
1
Explanation: The prices of chocolates are [2, 4, 6] and Geek had 5 coins with him. 
So he can only buy chocolate that costs 4 coins (since he always picks the costliest one).
*/

class Solution{
    public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        long long lo = 0, hi = n-1, ans = 0, indx, val;
        while(k > 0) {
            indx = val = -1;
            while(lo <= hi) {
                int mid = (lo + hi)/2, cur = shop.get(mid);
                if(cur > k) hi = mid - 1;
                else {
                    indx = mid, val = cur;
                    lo = mid + 1;
                }
            }
            if(indx == -1) break;
            lo = 0, hi = indx - 1;
            ans += k/val, k %= val;
        }
        return ans;
    }

};
