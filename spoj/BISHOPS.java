import java.util.*;
import java.io.*;
import java.math.BigInteger;

class BISHOPS {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = null;
        BigInteger two = new BigInteger("2");
        while((line = br.readLine()) != null){
            BigInteger n = new BigInteger(line);
            n = n.multiply(two);
            n = n.subtract(two);
            System.out.println(n);
        }
    }
}
