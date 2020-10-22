/* implement binary search to search a number

 */
package Practice;

import java.util.Scanner;

public class P3_BinarySearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("input the number to be searched");
        int n;
        n = sc.nextInt();
        int a[] = new int[10];
        for (int i = 0; i < 10; i++) {
            a[i] = sc.nextInt();
        }
        int high = 10, low = 0;
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (a[mid] == n) {
                n = 0;
                System.out.println("Number found");
                break;
            } else if (a[mid] < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (n != 0)
            System.out.println("Number not found");
    }

}
