/*
You are given two binary strings S and P, each with length N. A binary string contains only characters '0' and '1'. For each valid i, let's denote the i-th character of S by Si.

You have to convert the string S into P using zero or more operations. In one operation, you should choose two indices i and j (1≤i<j≤N) such that Si is '1' and Sj is '0', and swap Si with Sj.

Determine if it is possible to convert S into P by performing some operations.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains a single string S.
The third line contains a single string P.
Output
For each test case, print a single line containing the string "Yes" if it is possible to convert S into P or "No" otherwise (without quotes).

Constraints
1≤T≤105
1≤N≤105
S and P contain only characters '0' and '1'
the sum of N over all test cases does not exceed 105
Subtasks
Subtask #1 (20 points):

N≤14
the sum of N over all test cases does not exceed 100
Subtask #2 (30 points): the sum of N over all test cases does not exceed 1,000
Subtask #3 (50 points): original constraints

Example Input
3
2
00
00
3
101
010
4
0110
0011
Example Output
Yes
No
Yes
Explanation
Example case 1: The strings are already equal.

Example case 2: It can be showed that it is impossible to convert S into P.

Example case 3: You can swap S2 with S4. The strings will then be equal.
 */

package Codechef;

import java.util.Scanner;

public class One_0_Swaps {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            String s = sc.next();
            String p = sc.next();
            int s_zero = 0, s_one = 0, eq = 0;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == p.charAt(i)) {
                    eq++;
                } else {
                    if (s.charAt(i) == '0') s_zero++;
                    else s_one++;
                }
            }
            if (eq == n) System.out.println("Yes");
            else {
                int c1=0;
                if (s_zero !=  s_one ) System.out.println("No");
                else {
                    for(int i=0;i<n;i++){
                        if (s.charAt(i) != p.charAt(i)) {
                            if (s.charAt(i) == '0') {
                                if (c1 > 0) c1--;
                                else {i=n+3;c1=n+1;break;}
                            }
                            else c1++;
                        }
                    }
                    if(c1==n+1)
                    System.out.println("No");
                    else System.out.println("Yes");
                }
            }
            t = t - 1;
        }
    }
}
