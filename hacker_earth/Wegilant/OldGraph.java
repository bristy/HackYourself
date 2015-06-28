/**
 * @author: Brajesh
 * OldGraph .java
 */ 
import java.io.*;
import java.util.*;
public class OldGraph {
    public OldGraph () {
    }

      public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        
        String[] line = br.readLine().split(" ");
        long n = Long.parseLong(line[0]);
        long m = Long.parseLong(line[1]);
        
        for(int i = 0; i < m; i++) {
            line = br.readLine().split(" ");
            
 
        }
        long ret = (n * (n - 1) / 2 ) - (n - 1);
        System.out.println(ret);

    }
}
//OldGraph .java 

