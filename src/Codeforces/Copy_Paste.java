/*
BThero is a powerful magician. He has got n piles of candies, the i-th pile initially contains ai candies. BThero can cast a copy-paste spell as follows:

He chooses two piles (i,j) such that 1≤i,j≤n and i≠j.
All candies from pile i are copied into pile j. Formally, the operation aj:=aj+ai is performed.
BThero can cast this spell any number of times he wants to — but unfortunately, if some pile contains strictly more than k candies, he loses his magic power. What is the maximum number of times BThero can cast the spell without losing his power?

Input
The first line contains one integer T (1≤T≤500) — the number of test cases.

Each test case consists of two lines:

the first line contains two integers n and k (2≤n≤1000, 2≤k≤104);
the second line contains n integers a1, a2, ..., an (1≤ai≤k).
It is guaranteed that the sum of n over all test cases does not exceed 1000, and the sum of k over all test cases does not exceed 104.

Output
For each test case, print one integer — the maximum number of times BThero can cast the spell without losing his magic power.
 */
package Codeforces;

import java.util.Scanner;

public class Copy_Paste {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int min = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] < min) min = a[i];
            }
            if (k >= min) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] <= k) {
                        sum += (k - a[i]) / min;
                    }
                }
                sum = sum - (k - min) / min;
                System.out.println(sum);
            }
            else{
                System.out.println(0);
            }
            t--;
        }
    }
}
