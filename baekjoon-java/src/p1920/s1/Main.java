package p1920.s1;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static int binSrch(int[] arr, int target, int s, int e) {
        int c;
        while (s <= e) {
            c = s + (e - s) / 2;
            if (target > arr[c]) {
                s = c + 1;
            } else if (target < arr[c]) {
                e = c - 1;
            } else {
                return c;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ns = new int[n];
        for (int i=0;i<n;i++){
            ns[i] = sc.nextInt();
        }
        Arrays.sort(ns);
        int m = sc.nextInt();
        for (int i=0;i<m;i++){
            int resultIdx = binSrch(ns, sc.nextInt(), 0, n-1);
            System.out.println(resultIdx < 0 ? 0 : 1);
        }
        sc.close();
    }
}
