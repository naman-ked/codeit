/*
Geek wants to measure weight of some objects for which he has several iron blocks to compare with.
The weights of the iron blocks are powers of 2, i.e., their weights are 2 4 8 16..
If Geek is given an object of weight 5, he can use two blocks of weight 2, and another of weight 1 to determine the total weight of the object.
You will be given weight w of an object, and you will have to determine the minimum number of such iron blocks required to compare the weight of the object.
Note: Geek always has sufficient amount of blocks to weigh an object.
Example 1
Input:
w = 5
Output: 2
Explanation: 
If you will take one iron block of weight 4, and another of weight 1,
total weight will be 1+4=5.
There is no other combination of iron blocks that could give smaller answer.
*/

class Solution {
  public:
    int nBlocks(int w) {
        // code here
        int c=0;
        while(pow(2,c)<w){
            c++;
        }
        int res=0;
        int x=0;     
        while(c>=0 and w>0){
            x=pow(2,c);
            if(w>=x){
                res+=(w/x);
                w=w%x;
            }
            c--;
        }
        return res;
    }
};
