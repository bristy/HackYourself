/**
 * @author: Brajesh
 * OzGame .java
 */ 
import java.io.*;
import java.util.*;
public class OzGame {
    public OzGame () {
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-->0){
            int N = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            solve(N, line);
        }
    }

    private static void solve(int N, String[] line){
        int[] data = new int[N];
        for(int i = 0; i < N; i++){
            data[i] = Integer.parseInt(line[i]);
        }
        Arrays.sort(data);
        int ret = 0;
        for(int i = N - 1; i >= 0; i--) {
            if(i > 0){
                if(data[i] - 1 == data[i - 1]){
                    i--;
                }
            }
            ret++;
        }
        System.out.println(ret);
    }


}
//OzGame .java 

