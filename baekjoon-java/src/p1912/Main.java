package p1912;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] arr = br.readLine().split(" ");
        int sum = Integer.parseInt(arr[0]);
        int max = sum;

        for (int i=1;i<n;i++){
            int num = Integer.parseInt(arr[i]);
            sum = Math.max(num, num + sum);
            max = Math.max(sum, max);
        }
        System.out.println(max);
    }
}
