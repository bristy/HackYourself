package graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Queue;

/**
 * Created by brajesh.k on 13/10/16.
 */
public class Dhoom4 {
    private int[] keys;
    int target;
    int start;
    int n;
    int MOD = 100000;
    int MAX = MOD + 5;
    public static void main(String[] args) {
        new Dhoom4().solve();
    }

    private void solve() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] line = br.readLine().split(" ");
            start = Integer.parseInt(line[0]);
            target = Integer.parseInt(line[1]);

            n = Integer.parseInt(br.readLine());
            keys = new int[n];
            line = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                keys[i] = Integer.parseInt(line[i]) % MOD;
            }
            System.out.println(bfs(start % MOD));
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private int bfs(int start) {
        boolean[] visit = new boolean[MAX];
        Arrays.fill(visit, false);
        int[] dist = new int[MAX];
        Arrays.fill(dist, -1);

        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        dist[start] = 0;

        while (!q.isEmpty()) {
            int curr = q.poll();
            visit[curr] = true;
            if (target == curr) {
                break;
            }
            for (int i = 0; i < n; i++) {
                int to = (int) (((long)curr * keys[i]) % MOD);
                if (!visit[to]) {
                    q.add(to);
                    visit[to] = true;
                    dist[to] = dist[curr] + 1;
                }
            }
        }

        return dist[target];
    }
}
