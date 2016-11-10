package M372Div2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * Created by brajesh.k on 13/10/16.
 */
public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int[] friends = new int[line.length];
        for (int i = 0; i < line.length; i++) {
            friends[i] = Integer.parseInt(line[i]);
        }
        Arrays.sort(friends);
        System.out.println(friends[2] - friends[0]);
    }
}
