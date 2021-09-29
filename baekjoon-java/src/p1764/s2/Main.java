package p1764.s2;

import java.io.*;
import java.util.*;

public class Main {
    private static int binSrch(String[] arr, String target, int len) {
        int s=0, e=len-1, c;
        while (s <= e) {
            c = s + (e - s) / 2;
            if (target.compareTo(arr[c]) > 0) {
                s = c + 1;
            } else if (target.compareTo(arr[c]) < 0) {
                e = c - 1;
            } else {
                return c;
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] nums = br.readLine().split(" ");
        int n = Integer.parseInt(nums[0]);
        int m = Integer.parseInt(nums[1]);
        List<String> s = new ArrayList<>();

        String[] arr = new String[n];
        String[] arr2 = new String[m];
        for(int i=0;i<n;i++) {
            arr[i] = br.readLine();
        }
        for(int i=0;i<m;i++) {
            arr2[i] = br.readLine();
        }

        Arrays.sort(arr);
        Arrays.sort(arr2);

        for(int i=0;i<m;i++) {
            int resultIdx = binSrch(arr, arr2[i], n);
            if (resultIdx >= 0) {
                s.add(arr[resultIdx]);
            }
        }

        bw.write(String.valueOf(s.size()));
        bw.newLine();
        for (String s1 : s) {
            bw.write(s1);
            bw.newLine();
        }
        br.close();
        bw.close();
    }
}
