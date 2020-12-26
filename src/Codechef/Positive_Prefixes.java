/*
You are given two positive integers N and K, where K≤N. Find a sequence A1,A2,…,AN such that:

for each valid i, Ai is either i or −i
there are exactly K values of i such that 1≤i≤N and A1+A2+…+Ai>0
If there are multiple solutions, you may print any one of them. It can be proved that at least one solution always exists.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers N and K.
Output
For each test case, print a single line containing N space-separated integers A1,A2,…,AN.

Constraints
1≤T≤1,000
1≤K≤N≤1,000
Subtasks
Subtask #1 (10 points): N≤10
Subtask #2 (90 points): original constraints

Example Input
1
3 3
 */
package Codechef;

import java.util.Scanner;

public class Positive_Prefixes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int p=k,q=n-k;
            int i;
            for (i = 1; i <= n; i++) {
                if (q != 0) {
                    System.out.print(-i + " ");
                    q--;
                }
                else System.out.print(i + " ");
                i++;
                if (p > 0) {
                    System.out.print(i + " ");
                    p--;
                }
                else System.out.print(-i + " ");
            }
            System.out.println();
            t = t - 1;
        }
    }
}
