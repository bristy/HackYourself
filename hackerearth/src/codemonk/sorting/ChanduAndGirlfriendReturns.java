package codemonk.sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 26/06/16.
 */
public class ChanduAndGirlfriendReturns {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            solve(br);
        }
    }

    private static void solve(BufferedReader br) throws IOException {


        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        int A[] = new int[n];
        line = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(line[i]);
        }

        int B[] = new int[m];
        line = br.readLine().split(" ");
        for (int i = 0; i < m; i++) {
            B[i] = Integer.parseInt(line[i]);
        }

        int[] aux = new int[n + m];



        int l = 0;
        int r = 0;
        int k = 0;
        while (l < n && r < m) {
            if (A[l] >= B[r]) {
                aux[k] = A[l];
                k++;
                l++;
            } else {
                aux[k] = B[r];
                k++;
                r++;
            }
        }

        while (l < n) {
            aux[k] = A[l];
            k++;
            l++;
        }

        while (r < m) {
            aux[k] = B[r];
            k++;
            r++;

        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n + m; i++) {
            if (i != 0) {
                sb.append(" ");
            }
            sb.append(aux[i]);
        }

        System.out.println(sb);

    }
}
