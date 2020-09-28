/*Danik urgently needs rock and lever! Obviously, the easiest way to get these things is to ask Hermit Lizard for them.

Hermit Lizard agreed to give Danik the lever. But to get a stone, Danik needs to solve the following task.

You are given a positive integer n, and an array a of positive integers. The task is to calculate the number of such pairs (i,j) that i<j and ai & aj≥ai⊕aj, where & denotes the bitwise AND operation, and ⊕ denotes the bitwise XOR operation.

Danik has solved this task. But can you solve it?

Input
Each test contains multiple test cases.

The first line contains one positive integer t (1≤t≤10) denoting the number of test cases. Description of the test cases follows.

The first line of each test case contains one positive integer n (1≤n≤105) — length of the array.

The second line contains n positive integers ai (1≤ai≤109) — elements of the array.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For every test case print one non-negative integer — the answer to the problem.

Example
inputCopy
5
5
1 4 3 7 10
3
1 1 1
4
6 2 5 3
2
2 4
1
1
outputCopy
1
3
2
0
0
Note
In the first test case there is only one pair: (4,7): for it 4 & 7=4, and 4⊕7=3.

In the second test case all pairs are good.

In the third test case there are two pairs: (6,5) and (2,3).

In the fourth test case there are no good pairs.

*/

package Codeforces;


import java.util.Scanner;

public class Rock_Lever {

    public static long max_set_bit(long n) { //finding the maximum set bit in the integer
        long c = 0;
        while (n >= Math.pow(2, c)) c++;
        return c;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); //calling the scanner class
        int t = sc.nextInt(); //no. of test cases
        while (t > 0) {      //while loop for eah test case
            int n = sc.nextInt();  //no of elements in an array
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            long bit[] = new long[31];
            long sum = 0,x;
            for (int i = 0; i < n; i++) {
                x = max_set_bit(a[i]);
                bit[(int) x]++;
            }
            for (int j = 1; j < 31; j++) {
                sum += ((bit[j] * (bit[j] - 1)) / 2);  //for i<j how many pairs you can form
            }
            System.out.println(sum);
            t--;
        }

    }
}
