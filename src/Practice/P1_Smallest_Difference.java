/*
Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference. Return the difference.

Examples :

Input : A[] = {l, 3, 15, 11, 2}
        B[] = {23, 127, 235, 19, 8}
Output : 3
That is, the pair (11, 8)

Input : A[] = {l0, 5, 40}
        B[] = {50, 90, 80}
Output : 10
That is, the pair (40, 50)
 */

package Practice;

import java.util.Arrays;
import java.util.Scanner;

public class P1_Smallest_Difference {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int pair[] = new int[2];
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int b[] = new int[m];
        for (int i = 0; i < m; i++) {
            b[i] = sc.nextInt();
        }
        int index1=0,index2=0;
        Arrays.sort(a);
        Arrays.sort(b);
        int currentDiff=0,smallestDiff=Integer.MAX_VALUE,c,d;
        while(index1<n && index2<m){
            if(a[index1]==b[index2]){
                currentDiff=0;
                c=a[index1];
                d=a[index1];
                index1=n;
            }
            else if(a[index1]>b[index2]){
                currentDiff=a[index1]-b[index2];
                c=a[index1];
                d=b[index2];
                index2++;
            }
            else{
                currentDiff=b[index2]-a[index1];
                c=b[index2];
                d=a[index1];
                index1++;
            }
            if(currentDiff<smallestDiff){
                pair[0]=c;
                pair[1]=d;
                smallestDiff=currentDiff;
            }
        }
        System.out.println(smallestDiff);
        System.out.println(Arrays.toString(pair));
    }
}
