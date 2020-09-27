/* You are given an array a consisting of n integers numbered from 1 to n.

Let's define the k-amazing number of the array as the minimum number that occurs in all of the subsegments of the array having length k (recall that a subsegment of a of length k is a contiguous part of a containing exactly k elements). If there is no integer occuring in all subsegments of length k for some value of k, then the k-amazing number is −1.

For each k from 1 to n calculate the k-amazing number of the array a.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases. Then t test cases follow.

The first line of each test case contains one integer n (1≤n≤3⋅105) — the number of elements in the array. The second line contains n integers a1,a2,…,an (1≤ai≤n) — the elements of the array.

It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

Output
For each test case print n integers, where the i-th integer is equal to the i-amazing number of the array.

Example
inputCopy
3
5
1 2 3 4 5
5
4 4 4 4 2
6
1 3 1 5 3 1
outputCopy
-1 -1 3 2 1
-1 4 4 4 2
-1 -1 1 1 1 1

 */


package Codeforces;


import java.util.Arrays;
import java.util.Scanner;

public class k_Amazing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            Arrays.sort(a);

        }
    }
}
