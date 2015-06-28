/**
 * @author: Brajesh
 * Chocolates .java
 */ 
import java.io.*;
import java.util.*;
public class Chocolates {
    public Chocolates () {
    }

    private static int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a % b);
    }

    static class Node implements Comparable<Node>{
        int u;
        int v;
        int w;

        public Node(int a, int b, int c){
            u = a;
            v = b;
            w = c;
        }

        public int compareTo(Node another){
            return another.w - this.w; // for decending
        }
    }
    private static void solve(BufferedReader br) throws IOException{
        int u, v, w;
        String[] line = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);
        line = br.readLine().split(" ");
        int[] choc = new int[line.length];
        for(int i = 0; i < choc.length; i++){
            choc[i] = Integer.parseInt(line[i]);
        }

        Node[] edges = new Node[M];
        for(int i = 0; i < M; i ++){
            line = br.readLine().split(" ");
            u = Integer.parseInt(line[0]) - 1;
            v = Integer.parseInt(line[1]) - 1;
            w = gcd(choc[u], choc[v]);
            edges[i] = new Node(u, v, w);
        }

        // sort edges in decending order
        Arrays.sort(edges);
        boolean[] visited = new boolean[N];
        for(int i = 0; i < N - 1; i++){
            visited[i] = false;
        }

        int result = 0; // ans
        // traverse all edges
        for(Node ed : edges){
            u  = ed.u;
            v = ed.v;
            w = ed.w;
            if((u + v) % 2 > 0) { //  as per condition
                if(!visited[u] && !visited[v]){ // u and v are not visited
                    visited[u] = true;
                    visited[v] = true;
                    result += w;
                }
            }
        }
        System.out.println(result);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            solve(br);
        }
    }
}


//Chocolates .java 

