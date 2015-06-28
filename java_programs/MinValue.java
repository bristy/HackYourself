/**
 * @author: Brajesh
 * MinValue .java
 */ 

public class MinValue {
    public MinValue () {
    }

    public static void main(String[] args) {
        System.out.println(getMin(6));
    }
    public static int getMin(int n) {
        if(n == 1) {
            return 0;
        }

        int a = getMin(n - 1);
        int b = Integer.MAX_VALUE;
        if(n % 2 == 0){
            b = getMin(n / 2);
        }
        int c = Integer.MAX_VALUE;
        if(n % 3 == 0) {
            c = getMin(n / 3);
        }

        int result = Math.min(a, b);
        result = Math.min(result, c);
        return result + 1;

    }
}
//MinValue .java 

