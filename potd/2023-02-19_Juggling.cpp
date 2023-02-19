/*
Geek and Geekina are playing a Juggling Game. Geek hides the ball under one of three cups numbered 1, 2 and 3 and he *juggles any of the two distinct cups for 
n times and after each juggle Geekina predicts under which cup the ball is hidden. 
Find the cup under which ball should be hidden initially before start of game so that Geekina wins the maximum games and return the cup number and 
maximum wins possible with it.
You are given an integer n and a 2D list arr consisting of n juggles. Juggle i is given by [a,b,p] where a and b are juggled and 
p is predicted cup. If the maximum wins are same for two cups return the cup with lowest value.
Example 1:
Input :
N = 6
juggles = [[3, 1, 2],
[3, 2, 1],
[3, 2, 3],
[1, 2, 3],
[3, 2, 3],
[1, 3, 2]]

Output :
1 3
*/

class Solution {
  public:
    vector<int> juggling(vector<vector<int>> &arr,int n) {
        // code here
        int initial=1,count1=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]==initial)initial=arr[i][1];
            else if(arr[i][1]==initial)initial=arr[i][0];
            if(initial==arr[i][2]) count1++;
        }
        
        initial=2;
        int count2=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]==initial)initial=arr[i][1];
            else if(arr[i][1]==initial)initial=arr[i][0];
            if(initial==arr[i][2]) count2++;
        }
        
        initial=3;
        int count3=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]==initial)initial=arr[i][1];
            else if(arr[i][1]==initial)initial=arr[i][0];
            if(initial==arr[i][2]) count3++;
        }
        
        if(count1>=count2 and count1>=count3) return{1,count1};
        else if(count2>=count1 and count2>=count3) return{2,count2};
        else return{3,count3};
        
        }
};
