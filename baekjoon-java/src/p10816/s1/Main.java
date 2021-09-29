package p10816.s1;

import java.io.*;

public class Main {
    public static void merge(int[] arr, int start, int end) {
        int s1 = start;
        int e1 = (end - start) / 2 + start;
        int s2 = e1 + 1;
        int e2 = end;

        int len = end - start + 1;
        int t = 0;
        int[] tmp = new int[len];

        while(s1 <= e1 && s2 <= e2) {
            if (arr[s1] < arr[s2]) {
                tmp[t++] = arr[s1++];
            } else if (arr[s1] > arr[s2]) {
                tmp[t++] = arr[s2++];
            } else {
                tmp[t++] = arr[s1++];
                tmp[t++] = arr[s2++];
            }
        }

        while (s1 <= e1) {
            tmp[t++] = arr[s1++];
        }

        while (s2 <= e2) {
            tmp[t++] = arr[s2++];
        }

        if (start <= end){
            System.arraycopy(tmp, 0, arr, start, len);
        }
    }

    public static void mergeSort(int[] arr, int start, int end) {
        if(end == start){return;}
        int midLeft = (end - start) / 2 + start;
        int midRight = midLeft + 1;
        mergeSort(arr, start, midLeft);
        mergeSort(arr, midRight, end);
        merge(arr, start, end);
    }

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
        mergeSort(arr, 0, n-1);

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
