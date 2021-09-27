package p1018.s2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int count(String[] arr, int sr, int sc) {
        int cb = 0, cw = 0;
        for (int i=sr;i<sr+8;i++) {
            String sw = i%2==0 ? "WBWBWBWB" : "BWBWBWBW";
            String sb = i%2==0 ? "BWBWBWBW" : "WBWBWBWB";
            for (int j=0;j<8;j++) {
                if (arr[i].charAt(j+sc) != sb.charAt(j)) cb++;
                if (arr[i].charAt(j+sc) != sw.charAt(j)) cw++;
            }
        }
        return Math.min(cb, cw);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String mn = br.readLine();
        int m = Integer.parseInt(mn.split(" ")[0]);
        int n = Integer.parseInt(mn.split(" ")[1]);
        String[] sa = new String[m];
        int count = 32;

        for (int i=0;i<m;i++) {
            sa[i] = br.readLine();
        }

        for (int i=0;i<=m-8;i++) {
            for (int j=0;j<=n-8;j++) {
                count = Math.min(count(sa, i, j), count);
            }
        }

        System.out.println(count);
        br.close();
    }
}