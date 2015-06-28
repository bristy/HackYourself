/**
 * @author: Brajesh
 * FastFuriuous .java
 */ 
import java.io.*;
import java.util.*;
public class FastFuriuous {
    public FastFuriuous () {
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long brian;
        long dom;
        String[] line = br.readLine().split(" ");
        dom = getMax(line, n);
        line = br.readLine().split(" ");
        brian = getMax(line, n);
        if(brian > dom){
            System.out.println("Brian\n" + brian);
        } else if(dom > brian) {
            System.out.println("Don\n" + dom);
        } else {
            System.out.println("Tie\n" + dom);
        }
    }

    private static long getMax(String[] line, int n) {
        long brian = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                brian = Long.parseLong(line[0]);
            } else {
                
                brian = Math.max(brian, Math.abs(Long.parseLong(line[i]) - Long.parseLong(line[i - 1])));
            }
        }
        return brian;

    }


}
//FastFuriuous .java 

