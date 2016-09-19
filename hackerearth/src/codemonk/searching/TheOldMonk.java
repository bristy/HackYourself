package codemonk.searching;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 27/06/16.
 */
public class TheOldMonk {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            solve(br);
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        String[] line;
        int n = Integer.parseInt(br.readLine());
        long[] A = new long[n];
        line = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            A[i] = Long.parseLong(line[i]);
        }

        long[] B = new long[n];
        line = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            B[i] = Long.parseLong(line[i]);
        }

        int maxMonkiness = 0;
        for (int i = 0; i < n; i++) {
            int j = indexOf(B, A[i], i, n - 1);
            maxMonkiness = Math.max(maxMonkiness, j - i);
        }
        System.out.println(maxMonkiness);

    }

    private static int indexOf(long[] B, long value, int lo, int hi) {

        int pos = 0;
        while (hi - lo >= 0) {
            int mid = (hi + lo) / 2;
            if (B[mid]>= value) {
                lo = mid + 1;
                pos = mid;
            } else {
                hi = mid - 1;
            }
        }
        return pos;
    }
}
