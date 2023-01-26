/* 
Given a number k and string num of digits (0 to 9) denoting a positive integer. 
Find a string denoting the lowest integer number possible by removing k digits from num, without changing their order.
Note: num will not contain any leading zero.

Input:
k = 2
num = "143729"
Output: "1329"
Explanation: 1329 is the minimum number
possible after removing '4' and '7'.
*/

string buildLowestNumber(string num, int k)
{
    stack<char> ch;
    for(char c:num){
        while(ch.size()>0 and ch.top()>c and k>0){
            ch.pop();
            k--;
        }
        ch.push(c);
    }
    while(k>0 and ch.size()>0){
        ch.pop();
        k--;
    }
    string s="";
    while(ch.size()>0){
        s=ch.top()+s;
        ch.pop();
    }
    
    int i=0;
    while(s[i]=='0' and i<s.size())i++;
    
    s=s.substr(i);
    if(s=="")s="0";
    return s;
}
