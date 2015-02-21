import java.util.*;
import java.io.*;

public class SherlockPermute {
    private static final long MOD = 1000000007;
    public static void main(String[] argvs){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            String[] line;
            while(t-- > 0){
                line = br.readLine().split(" ");
                solve(Long.parseLong(line[0]), Long.parseLong(line[1]) - 1, MOD);
            }
        } catch(IOException io){
            io.printStackTrace();
        }
    }

    private static void solve(long n, long m, long mod){
        long ret = 1;
        long tt = n + m;
        for(long i = 1; i <= n; i++){
            ret = (ret * (tt - i + 1) % mod);
        }

        System.out.println(ret);
    }
}
