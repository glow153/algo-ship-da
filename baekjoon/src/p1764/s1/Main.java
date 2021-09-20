package p1764.s1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] n = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        Set<String> s1 = new HashSet<>();
        Set<String> s2 = new HashSet<>();
        for(int i=0;i<n[0];i++) {
            s1.add(br.readLine());
        }
        for(int i=0;i<n[1];i++) {
            s2.add(br.readLine());
        }
        s1.retainAll(s2);
        String[] result = s1.toArray(new String[0]);
        Arrays.sort(result);

        System.out.println(result.length);
        for (String s: result){
            System.out.println(s);
        }
    }
}
