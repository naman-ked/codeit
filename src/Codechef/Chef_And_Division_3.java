/*
Chef wants to host some Division-3 contests. Chef has N setters who are busy creating new problems for him. The ith setter has made Ai problems where 1≤i≤N.

A Division-3 contest should have exactly K problems. Chef wants to plan for the next D days using the problems that they have currently. But Chef cannot host more than one Division-3 contest in a day.

Given these constraints, can you help Chef find the maximum number of Division-3 contests that can be hosted in these D days?

Input:
The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers - N, K and D respectively.
The second line of each test case contains N space-separated integers A1,A2,…,AN respectively.
Output:
For each test case, print a single line containing one integer ― the maximum number of Division-3 contests Chef can host in these D days.

Constraints
1≤T≤103
1≤N≤102
1≤K≤109
1≤D≤109
1≤Ai≤107 for each valid i
Subtasks
Subtask #1 (40 points):

N=1
1≤A1≤105
Subtask #2 (60 points): Original constraints

Sample Input:
5
1 5 31
4
1 10 3
23
2 5 7
20 36
2 5 10
19 2
3 3 300
1 1 1
Sample Output:
0
2
7
4
1
 */

package Codechef;

import java.util.Scanner;

public class Chef_And_Division_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int d = sc.nextInt();
            int sum=0;
            int  a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                sum+=a[i];
            }
            System.out.println(Math.min(d,sum/k));
            t = t - 1;
        }
    }
}
