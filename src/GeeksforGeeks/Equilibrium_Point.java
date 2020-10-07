/*
Given an array A of N positive numbers. The task is to find the first Equilibium Point in the array.
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:

Input:
N = 1
A[] = {1}
Output: 1
Explanation: Since its the only
element hence its the only equilibrium
point.
Example 2:

Input:
N = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case
equilibrium point is at position 3
as elements before it (1+3) =
elements after it (2+2).


Your Task:
The task is to complete the function equilibriumPoint() which takes the array and N as input parameters and returns the point of equilibrium. Return -1 if no such point exists.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 106
1 <= A[i] <= 108
 */
package GeeksforGeeks;

import java.util.Scanner;

public class Equilibrium_Point {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int back_sum[] = new int[n];
        int forward_sum[] = new int[n];
        back_sum[n-1]=0;
        for( int i = n-1; i > 0; i--)
        {
            back_sum[i-1]=back_sum[i]+a[i];
        }
        forward_sum[0]=0;
        for(int i = 0; i < n-1; i++)
        {
            forward_sum[i+1]=forward_sum[i]+a[i];
        }
        for(int i = 0; i < n; i++){
            if(forward_sum[i]==back_sum[i]){
                n=0;
                System.out.println(i+1);
            }
        }
        if(n!=0)
        System.out.println(-1);
    }
}
