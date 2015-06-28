/**
 * @author: Brajesh
 * TwoButtons .java
 */ 
import java.io.*;
import java.util.*;
public class TwoButtons {
    public TwoButtons () {
    }
    static void solve(int curr, int target){
        Queue<Integer> Q = new LinkedList<Integer>();
        int d[] = new int[20002];
        d[curr] = 0;
        Q.add(curr);
        while(!Q.isEmpty()){
            int p = Q.remove();
            if(p == target){
                System.out.println(d[p]);
                return;
            }
            if(p > 0 && d[p - 1] < d[p] + 1){
                d[p - 1] = d[p] + 1;
                Q.add(p - 1);
            }
            if(p * 2 <= target * 2 && d[p * 2] < d[p] +  1){
                d[p * 2] = d[p] + 1;
                Q.add(p * 2);
            }
        }
    }

    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        solve(n, m);
    }
}
//TwoButtons .java 

