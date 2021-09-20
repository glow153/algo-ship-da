package p1764.s2;

import java.io.*;
import java.util.*;

public class Main {
    private static int getCurrent(int s, int e){
        return Math.max(s+(e-s)/2, 0);
    }
    private static int binSrch(String[] a, String target, int start, int end, int current){
        int newStart, newEnd;

        if (target.compareTo(a[current]) > 0) {
            binSrch(a, target, current + 1, end, getCurrent());
        } else if (target.compareTo(a[current]) < 0) {
            binSrch(a, target, start, current - 1, current - (current - 1));
        } else {
            return current;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] nums = br.readLine().split(" ");
        int n = Integer.parseInt(nums[0]);
        int m = Integer.parseInt(nums[1]);

        String[] a1 = new String[n];
        String[] a2 = new String[m];
        for(int i=0;i<n;i++) {
            a1[i] = br.readLine();
        }
        for(int i=0;i<m;i++) {
            a2[i] = br.readLine();
        }

        Arrays.sort(a1);
        Arrays.sort(a2);

        List<String> s = new ArrayList<>();
        int t=0, j=0;
        for (int i=0;i<a1.length;i++) {
            for (j=t;j<a2.length;j++){
                if(a1[i].equals(a2[j])) {
                    s.add(a2[j]);
                    t = j+1;
                    break;
                }
            }
            if (t==j) break;
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
