/**
 * @author: Brajesh
 * AddSub .java
 */ 
import java.io.*;
import java.util.*;
public class AddSub {
    public AddSub () {
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-->0){
            String[] line = br.readLine().split(" ");
            int N = Integer.parseInt(line[0]);
            int K = Integer.parseInt(line[1]);
            line = br.readLine().split(" ");
            int[] A = new int[N + 1];
            for(int i = 0; i < N; i++){
                A[i + 1] = Integer.parseInt(line[i]);
            }
            A[0] = -1;
            Arrays.sort(A);
            int cost = 1000000000;
            for(int i = 1; i + K - 1 <= N; i++){
                cost = Math.min(cost, getCost(i, i + K -1, A));
            }
            System.out.println(cost);
        }
    }

    private static int getCost(int l, int r, int[] A) {
        int len = r - l + 1;
        int ml, mr;
        if(len % 2 == 0){
            // even two median
            ml = A[(l + r) / 2];
            mr = A[(l + r + 1) / 2];
        } else {
            ml = mr = A[(l + r) / 2];
        }
        int cl = 0, cr = 0;
        for(int i = l; i <= r; i++){
            int dl = ml - A[i];
            int dr = mr - A[i];
            cl += dl > 0 ? 3*dl : -5*dl;
            cr += dr > 0 ? 3*dr : -5*dr;
        }

        return Math.min(cl, cr);
    }

}
//AddSub .java 

