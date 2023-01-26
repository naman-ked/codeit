/*
You are given a binary string str. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and complement the characters between L and R
i.e strL, strL+1, , strR. By complement, we mean change character 0 to 1 and vice-versa.

You task is to perform ATMOST one operation such that in final string number of 1s is maximised.
If there is no need to completement, i.e., string contains all 1s, return -1. 
Else, return the two values denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.
Input:
N = 3
str = "111"
Output: -1

Input:
N = 2
str = "01"
Output: 1 1
Explanation: After complementing [1, 1] 
the string becomes "11".
*/


  int net_diff = 0;
    int largest = 0;
    int final_left = -1, final_right = -1;
    int left = -1;

    for(int i = 0; i < n; i++){
        if (str[i] == '0'){
            net_diff++;
        }
        else{
            net_diff--;
            if(net_diff < 0){
                net_diff = 0;
                left = -1;
            }
        }

        if(net_diff == 1 && left == -1){
            left = i;
        }

        if(largest < net_diff){
            largest = net_diff;
            final_left = left + 1;
            final_right = i + 1;
        }
    }

    std :: vector<int> ans;
    if (final_left == -1){  // We never got our desired substring
        ans.push_back(-1);
        return ans;
    }
    ans.push_back(final_left);
    ans.push_back(final_right);

    return ans;
