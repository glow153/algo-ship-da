package p2751;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class Main {
    private static Random rand = new Random();
    public static int partition(int[] arr, int l, int h) {
        int pi = l + rand.nextInt(h - l);
        int p = arr[pi];
        int t;

        while (l <= h) {
            while(arr[l] < p) l++;
            while(p < arr[h]) h--;
            if (l <= h) {
                t = arr[l];
                arr[l] = arr[h];
                arr[h] = t;
                l++;
                h--;
            }
        }
        return l;
    }

    public static void quickSort(int[] arr, int start, int end) {
        if (start >= end) return;
        int m = partition(arr, start, end);
        quickSort(arr, start, m);
        quickSort(arr, m + 1, end);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        quickSort(arr, 0, n-1);
        for (int a : arr){
            System.out.println(a);
        }
    }
}
