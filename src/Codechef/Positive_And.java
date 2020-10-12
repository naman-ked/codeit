/*
A permutation p1,p2...pN of {1,2,...,N} is beautiful if pi&pi+1 is greater than 0 for every 1≤i<N . You are given an integer N, and your task is toconstruct a beautiful permutation of length N or determine that it's impossible.
Note that a&b denotes the bitwise AND of a and b.
Input:
First line will contain T, number of testcases. Then the testcases follow. Each testcase contains a single line of input, an integer N.
Output:
For each test case output −1 if there is no suitable permutation of length N, otherwise output N integers in a single line which form a beautiful permutation. If there are multiple answers output any of them.
Constraints
1≤N≤105
The sum of N over all test cases does not exceed 106
Subtasks
50 points : 1≤N,T≤9
50 points : Original constraints
Sample Input:
3
4
3
5
Sample Output:
-1
1 3 2
2 3 1 5 4
 */


package Codechef;

import java.util.Scanner;


public class Positive_And {

    public static boolean check_two_power(long x) {
        return (x != 0) && ((x & (x - 1)) == 0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            long n = sc.nextLong();
            if (n == 1) {
                System.out.println(1);
            } else if (check_two_power(n)) {
                System.out.println(-1);
            } else {
                int c = 0;
                System.out.print("2 1 3 ");
                for (int i = 4; i <= n; i++) {
                    if (check_two_power(i)) {
                        System.out.print(i + 1 + " ");
                        System.out.print(i + " ");
                        c = 0;
                        i++;
                    } else {
                        System.out.print(i + " ");
                    }
                }
                System.out.println();
            }
            t--;
        }
    }
}
