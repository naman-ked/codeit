/*
Alice has a very complex machine ― when fed with a sequence A1,A2,…,AN, it produces a sequence B1,B2,…,BN, where for each valid i, Bi is the largest index j such that Ai divides Aj (since Ai divides itself, such an index always exist). For example, if the machine is fed with A=[2,6,5,3,4], it produces B=[5,2,3,4,5].

Alice gave you a sequence B that was produced by the machine. Find an integer sequence A such that when it is fed into the machine, then the machine produces the sequence B. Alice does not like huge integers, so make sure that 1≤Ai≤4⋅106 holds for each valid i.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers B1,B2,…,BN.
Output
For each test case, print a single line containing N space-separated integers A1,A2,…,AN. For each valid i, 1≤Ai≤4⋅106 should hold.

If there are multiple solutions, you may print any of them. It is guaranteed that at least one solution exists.

Constraints
1≤T≤2⋅104
1≤N≤105
1≤Bi≤N for each valid i
the sum of N over all test cases does not exceed 2⋅105
Subtasks
Subtask #1 (20 points): B1,B2,…,BN are pairwise distinct

Subtask #2 (80 points): original constraints

Example Input
2
5
5 2 3 4 5
4
4 4 4 4
Example Output
2 6 5 3 4
2 6 3 12
 */


package Codechef;

import java.util.Arrays;
import java.util.Scanner;

public class RESTORE {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int t= sc.nextInt();
        while(t-->0)
        {
            int n= sc.nextInt();
            int a[]= new int[n];
            int b[]= new int[n];
            for(int i=0; i<n; i++)
                b[i]= sc.nextInt();

            int j=1;
            for(int i=n-1; i>=0; i--)
            {
                if(b[i]==(i+1))
                {
                    a[i]=j;
                    j++;
                }
                else
                {
                    a[i]=a[b[i]-1];
                }
            }
            for(int i=0; i<n; i++)
            {
                System.out.print(a[i]+" ");
            }
            System.out.println();
        }
            }
    }
