package p10816;

import java.io.*;
import java.util.Arrays;

public class Main {
    private static int binSrch(int target, int[] arr, int start, int end) {
        int s = start, e = end, c;
        int count = 0;
        while(s <= e) {
            c = s + (e - s) / 2;
            if (arr[c] < target) {
                s = c + 1;
            } else if (target < arr[c]) {
                e = c - 1;
            } else {
                count += 1;
                count += binSrch(target, arr, s, c - 1);
                count += binSrch(target, arr, c + 1, e);
                break;
            }
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int m = Integer.parseInt(br.readLine());
        int[] arr2 = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(arr);
        for(int i=0;i<m;i++){
            int count = binSrch(arr2[i], arr, 0, n-1);
            sb.append(count).append(' ');
        }
        bw.write(sb.toString());
        bw.newLine();
        bw.flush();
        br.close();
        bw.close();
    }
}
