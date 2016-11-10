package graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * Created by brajesh.k on 12/10/16.
 */
public class AgitatedChandan {

    static int n;
    static List<List<Pair<Integer, Integer>>> graph;
    static boolean[] visit;
    static int[] dist;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-->0) {
            solve(br);
        }

    }

    private static void solve(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());
        graph = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        String[] line;
        for (int i = 0; i < n - 1; i++) {
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]) - 1;
            int b = Integer.parseInt(line[1]) - 1;
            int c = Integer.parseInt(line[2]);
            graph.get(a).add(new Pair<>(b, c));
            graph.get(b).add(new Pair<>(a, c));
        }
        visit = new boolean[n];
        dist = new int[n];
        int v = bfs(0);
        v = bfs(v);
        int pay = dist[v];
        int d = dist[v];
        if (pay > 10000) {
            pay = 10000;
        } else if (pay > 1000) {
            pay = 1000;
        } else if (pay > 100) {
            pay = 100;
        } else {
            pay = 0;
        }
        System.out.println(pay + " " + d);
    }

    private static int bfs(int start) {


        Arrays.fill(visit, false);

        Arrays.fill(dist, 0);

        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        dist[start] = 0;
        visit[start] = true;
        int maxDist = 0;
        int maxNode = start;
        while (!queue.isEmpty()) {
            int p = queue.poll();
            for (Pair<Integer, Integer> v: graph.get(p)) {
                if (!visit[v.fst]) {
                    int cost = dist[p] + v.snd;
                    dist[v.fst] = cost;
                    queue.add(v.fst);
                    visit[v.fst] = true;
                    if (dist[v.fst] > maxDist) {
                        maxDist = dist[v.fst];
                        maxNode = v.fst;
                    }
                }
            }
        }
        return maxNode;
    }



    public static class Pair<A, B> {
        public final A fst;
        public final B snd;

        public Pair(A var1, B var2) {
            this.fst = var1;
            this.snd = var2;
        }

        public String toString() {
            return "Pair[" + this.fst + "," + this.snd + "]";
        }

        public boolean equals(Object var1) {
            return var1 instanceof Pair && Objects.equals(this.fst, ((Pair)var1).fst) && Objects.equals(this.snd, ((Pair)var1).snd);
        }

        public int hashCode() {
            return this.fst == null?(this.snd == null?0:this.snd.hashCode() + 1):(this.snd == null?this.fst.hashCode() + 2:this.fst.hashCode() * 17 + this.snd.hashCode());
        }

        public static <A, B> Pair<A, B> of(A var0, B var1) {
            return new Pair(var0, var1);
        }
    }

}


