package p1018.s1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int count(boolean[][] arr, int sr, int sc) {
        int cb = 0, cw = 0; // Count Wrong cell If First cell were Black/White
        boolean b = true;

        for (int i=sr;i<sr+8;i++) {
            for (int j=sc;j<sc+8;j++) {
                if (arr[i][j] == b) cb++;
                else                cw++;
                b = !b;
            }
            b = !b;
        }

        return Math.min(cb, cw);
    }

    public static void main(String[] args) throws IOException {
        boolean[][] board = new boolean[50][50];
        int count = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String mn = br.readLine();
        int m = Integer.parseInt(mn.split(" ")[0]);
        int n = Integer.parseInt(mn.split(" ")[1]);
        count = 32;

        for (int i=0;i<m;i++) {
            String line = br.readLine();
            for (int j=0;j<n;j++) {
                if (line.charAt(j) == 'B') {
                    board[i][j] = false;
                }
                if (line.charAt(j) == 'W') {
                    board[i][j] = true;
                }
            }
        }

        for (int i=0;i<=m-8;i++) {
            for (int j=0;j<=n-8;j++) {
                count = Math.min(count(board, i, j), count);
            }
        }

        System.out.println(count);
        br.close();
    }
}