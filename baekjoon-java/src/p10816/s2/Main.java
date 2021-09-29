package p10816.s2;

import java.io.*;
import java.util.Arrays;

public class Main {
    public static int lowerBound(int[] arr, int target) {
        int s = 0, e = arr.length;
        while(s < e) {
            int c = s + (e - s) / 2;
            if (arr[c] < target) {
                s = c + 1;
            } else {
                e = c;
            }
        }
        return s;
    }

    public static int upperBound(int[] arr, int target) {
        int s = 0, e = arr.length;
        while(s < e) {
            int c = s + (e - s) / 2;
            if (target < arr[c]) {
                e = c;
            } else {
                s = c + 1;
            }
        }
        return s;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        String[] sarr = br.readLine().split(" ");
        int m = Integer.parseInt(br.readLine());
        String[] sarr2 = br.readLine().split(" ");

        int[] arr = new int[n];
        for(int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(sarr[i]);
        }
        Arrays.sort(arr);

        for(int j=0;j<m;j++){
            int count = upperBound(arr, Integer.parseInt(sarr2[j])) - lowerBound(arr, Integer.parseInt(sarr2[j]));
            sb.append(count).append(' ');
        }
        bw.write(sb.toString());
        bw.newLine();
        bw.flush();
        br.close();
        bw.close();
    }
}
