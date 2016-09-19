package codemonk.arraystring;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 23/06/16.
 */
public class PrateekAndFriend {

    public static void main(String[] args) {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    protected static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int[] cost = new int[100001];
        for (int test = 0; test < t; test++) {
            int n;
            long k;
            String[] line = br.readLine().split(" ");
            n = Integer.parseInt(line[0]);
            k = Long.parseLong(line[1]);
            for (int i = 0; i < n; i++) {
                cost[i] = Integer.parseInt(br.readLine());
            }

            int lo = 0;
            int hi = 0;
            long sum = 0;
            while (hi < n) {
                if (sum > k) {
                    sum -= cost[lo];
                    lo++;
                } else if (sum < k) {
                    sum += cost[hi];
                } else {
                    break;
                }
            }
            if (sum == k) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
