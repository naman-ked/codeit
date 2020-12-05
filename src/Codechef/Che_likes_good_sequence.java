/*
Chef calls a sequence good if it does not contain any two adjacent identical elements.

Initially, Chef has a sequence a1,a2,…,aN. He likes to change the sequence every now and then. You should process Q queries. In each query, Chef chooses an index x and changes the x-th element of the sequence to y. After each query, can you find the length of the longest good subsequence of the current sequence?

Note that the queries are not independent.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and Q.
The second line contains N space-separated integers a1,a2,…,aN.
Q lines follow. Each of these lines contains two space-separated integers x and y describing a query.
Output
After each query, print a single line containing one integer ― the length of the longest good subsequence.

Constraints
1≤T≤5
1≤N,Q≤105
1≤ai≤109 for each valid i
1≤x≤N
1≤y≤109
Subtasks
Subtask #1 (35 points): Q=1
Subtask #2 (65 points): original constraints

Example Input
1
5 2
1 1 2 5 2
1 3
4 2
Example Output
5
3
 */
package Codechef;


import java.util.Scanner;


public class Che_likes_good_sequence {

    public static int longest(long a[], int n) {
        int c = 0, h = 0;
        for (int i = 0; i < n - 1; i++) {
            c++;
            if (a[i] == a[i + 1]) {
                if (c > h) h = c;
                c = 1;
            }
        }
        if (c != 1 && c > h) {
            h = c;
            h++;
        }
        return h;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            int q = sc.nextInt();
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
            }
            while (q > 0) {
                int x = sc.nextInt();
                long y = sc.nextLong();
                a[x - 1] = y;
                System.out.println(longest(a, n));
                q--;
            }

            t--;
        }
    }
}
