package Codechef;

import java.util.Arrays;
import java.util.Scanner;

public class Vaccine_Distribution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            int d = sc.nextInt();
            int  a[] = new int[n];
            int old=0;
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                if(a[i]>=80 || a[i]<=9)old++;
            }
            n=n-old;
            if(old%d==0)old=(old/d);
            else old=(old/d) + 1;
            if(n%d==0)n=n/d;
            else n=(n/d)+1;
            System.out.println(old+n);
            t--;
        }
    }
}
