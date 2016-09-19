/**
 * @author: Brajesh
 * Chain .java
 */ 
import java.io.*;

public class Chain {
    public Chain () {
    }
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int MOD = 1000003;
        long info[] = new long[MOD + 1];
        info[0] = 1;
        for(int i = 1; i <= MOD; i++){
            info[i] = (i * info[i - 1] % MOD);
        }
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            String[] line = br.readLine().split(" ");
            long N = Long.parseLong(line[0]);
            long X = Long.parseLong(line[1]);
            if(N >= MOD){
                System.out.println("0");
            } else {
                System.out.println((info[(int)N] * (X % MOD)) % MOD);
            }
        }
    }
}
//Chain .java 

