package codemonk.searching;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * Created by brajesh.k on 26/06/16.
 */
public class DiscoverTheMonk {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);
        line = br.readLine().split(" ");
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(line[i]);
        }
        Arrays.sort(A);

        for (int i = 0; i < q; i++) {
            int x = Integer.parseInt(br.readLine());
            if (indexOf(A, 0, n - 1, x) != -1){
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

    }

    private static int indexOf(int[] A, int lo, int hi, int val) {

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (A[mid] == val) {
                return mid;
            } else if (A[mid] < val) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
}
