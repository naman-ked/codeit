/*
You are given a string S. You can get a coin by choosing and removing three characters from S if the chosen characters form a palindrome in some order (possibly different from their order in the string). This operation may be performed repeatedly on the resulting string. Find the maximum number of coins you can get.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S.
Output
For each test case, print a single line containing one integer ― the maximum number of coins you can get.

Constraints
1≤T≤10
1≤|S|≤105
S contains only lowercase English letters
Subtasks
Subtask #1 (20 points): S contains only letters 'a' and 'b'

Subtask #2 (20 points):

1≤|S|≤100
S contains only letters 'a', 'b' and 'c'
Subtask #3 (60 points): original constraints

Example Input
2
abcd
codechef
Example Output
0
2
 */

package Codechef;

import java.util.Arrays;
import java.util.Scanner;

public class Three_Letters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            String s= sc.next();
            int n= s.length();
            char []arr = s.toCharArray();
            Arrays.sort(arr);
            String str=String.valueOf(arr);
            int two=0,c=1;
            for(int i=1;i<n;i++){
                if(str.charAt(i)==str.charAt(i-1)){c++;}
                else{
                    two=two+(c/2);
                    c=1;
                }
            }
            if(c>1)two=two+(c/2);
            two=Math.min(two,n/3);
            System.out.println(two);
            t=t-1;
        }
    }
}
