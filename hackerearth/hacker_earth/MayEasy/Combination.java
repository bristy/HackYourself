/**
 * @author: Brajesh
 * Combination .java
 */ 
import java.io.*;
import java.util.*;

public class Combination {
    public Combination () {
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
           String[] line = br.readLine().split(" ");
           long N = Long.parseLong(line[0]);
           long M = Long.parseLong(line[1]);
           if(M == 1) {
            System.out.println(N);
           } else {
               long ret = 0;
                while(N != 0) {
                    ret += N % M;
                    N /= M;
                }
                System.out.println(ret);
           }
        }
    }
}
//Combination .java 

