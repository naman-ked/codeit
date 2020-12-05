package Codechef;

import java.util.Scanner;

public class Gasoline_Intro {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long sum=0;
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            if(a[0]==0) {
                System.out.println(0);
            }
            else {
                long fuel=a[0],sum=a[0];
                for(int i=1;i<n;i++){
                    sum=sum+a[i];
                    fuel=fuel+a[i]-1;
                    if(fuel==0)break;
                }
                System.out.println(sum);
            }
        }
    }
}
