/*
Given a number n, print n-th Fibonacci Number.
Examples:

Input  : n = 2
Output : 1

Input  : n = 9
Output : 34
 */
package Practice;

import java.util.Scanner;
//Time: O(N) Space:O(1)
//iterative method
public class P2_Nth_Fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int a=0;
        int b=1,c=0;
        if(n==1)System.out.println("The "+n+"th fibonacci number is "+a);
        else if(n==2)System.out.println("The "+n+"th fibonacci number is "+b);
        else {
            for(int i=3;i<=n;i++)
            {
                c=a+b;
                a=b;
                b=c;
            }
            System.out.println("The "+n+"th fibonacci number is "+c);
        }

    }
}
