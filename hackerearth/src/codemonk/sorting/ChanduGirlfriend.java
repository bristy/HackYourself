package codemonk.sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * Created by brajesh.k on 23/06/16.
 */
public class ChanduGirlfriend {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());;
            String[] line = br.readLine().split(" ");
            int[] data = new int[n];
            for (int j = 0; j < n; j++) {
                data[j] = Integer.parseInt(line[j]);
            }
            Arrays.sort(data);
            for (int j = n - 1; j >=0 ; j--) {
                if (j != n - 1) {
                    System.out.print(" ");
                }
                System.out.print(data[j]);
            }
            System.out.println();
        }
    }
}
