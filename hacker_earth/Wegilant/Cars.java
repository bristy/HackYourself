/**
 * @author: Brajesh
 * Cars .java
 */ 

import java.io.*;

public class Cars {
    public Cars () {
    }
    
    private static void testOK(char[] name) {
        int len = name.length;
        if(len % 3 != 0) {
            System.out.println("Not OK");
            return;
        }
        int jcount = 0;
        int jlen = -1;
        int prev = 0;
        int i = 1;
        for(; i < len; i++) {
            if(name[i] != name[i - 1]) {
                jcount++; // new junction
                if(jlen == -1) {
                    jlen = (i - prev);
                } else if(jlen != (i - prev)) {
                    System.out.println("Not OK");
                    return;
                }
                prev = i;
            }
        }

        if(jcount == 2 && jlen == (i - prev)) {
            System.out.println("OK");
        } else {
            System.out.println("Not OK");
        }

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        while(n-- > 0) {
            testOK(br.readLine().toCharArray());
        }
    }
}
//Cars .java 

