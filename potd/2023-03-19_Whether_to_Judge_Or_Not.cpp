/*
Geek is conducting a coding event for his college students, but you know like Geek his fellow mates are too much excited, and in the excitement, 
they are making submissions too frequently.So Geek wants your help to avoid judging too frequent submissions. 
He asked you to implement the class GFG() which has two functions 
Constructor(int gap) - It accepts a single integer 'k' which denotes that a user's submission is judged only if he has not made any submission in the past or 
made a submission at least k seconds ago.
judgeOrNot(String submissionId) - It accepts submissionId as the argument and returns true if it is required to judge the submission otherwise it will return false.

The submissionId is a string that contains a username and a timestamp separated by an '@' symbol.
The timestamp is in the format 'hh:mm:ss', representing hours, minutes, and seconds, respectively. 
The submissions will be given in increasing order of time only.
Note: The submissions will be given in non-decreasing order of time only i.e. if 00:00:00 is appearing after 23:59:59 then consider it to be of the next day.

Input:
Function calls - 
[Constructor, judgeOrNot, judgeOrNot, judgeOrNot, judgeOrNot, judgeOrNot]

arguments -
[5, "paras@08:01:12", "aayush@08:01:13", "naman@08:01:13", "paras@08:01:16", "paras@08:01:17"]

Output:
[true, true, true, false, true]

Explanation:
In this case, the judgeOrNot() function should return [true, true, true, false, true]. 
The first three submissions are all from new users, so they should be judged. 
The fourth submission is from "paras," but it comes too soon after his last submission (less than 5 seconds), so it should not be judged. 
The fifth submission is from "paras" and comes after 5 seconds since his last (judged) submission, so it should be judged.

*/

class Gfg {
  public:
    int k;
    unordered_map<string,string> m;
    Gfg(int gap){
        k=gap;
    }
    
     long long int getTimeInSeconds(string str)
    {
 
        vector<int> curr_time;
        istringstream ss(str);
        string token;
 
        while (getline(ss, token, ':')) {
 
            curr_time.push_back(stoi(token));
        }
 
        long long int t = curr_time[0] * 60 * 60
                          + curr_time[1] * 60
                          + curr_time[2];
 
        return t;
    }
    
    bool judgeOrNot(string &submissionId) {
        string s1="",s2="";
        int flag=0;
        for(char s:submissionId){
            if(s=='@'){
                flag=1;
                continue;
            }
            if(flag==1)s2+=s;
            else s1+=s;
        }
        
        if(m.find(s1)==m.end()){
            m[s1]=s2;
            return true;
        }
        else{
            long long int t1 = getTimeInSeconds(m[s1]);
            long long int t2 = getTimeInSeconds(s2);
            long long int time_diff;
            if(t2>=t1) time_diff=t2-t1;
            else{
                time_diff=t1-t2;
                time_diff=(24*60*60)-time_diff;
            }
                        
            
            
            if(time_diff>=k){
                m[s1]=s2;
                return true;
            }
            return false;
        }
    }
};
