/**
 * @author: Brajesh
 * CutString .java
 */ 

public class CutString {
    public CutString () {
    }

    private static boolean isPowerFive(String str){
        int n = str.length();
       if(n == 0){
        return false;
       } 
       if(str.charAt(0) == '0'){
        return false;
       }

       long num = 0;
       for(int i = 0; i < n; i++){
            int val = (str.charAt(i) - '0');
            num = num * 2 + val;
       }
       while(num % 5 == 0){
            num = num / 5;
       }

       if(num == 1){
        return true;
       }

       return false;
    }
    static int getMin(String S){
        int n = S.length();
       int dp[] = new int[100];
      for(int i = 0; i < n; i++){
          dp[i] = -1;
          if(isPowerFive(S.substring(0, i + 1))) {
            dp[i] = 1;
          } else {
            for(int j = 1; j <= i; j++ ){
                if(isPowerFive(S.substring(j, i + 1)) && dp[j - 1] != -1){
                    if(dp[i] == -1 || dp[i] > dp[j - 1] + 1){
                        dp[i] = dp[j - 1] + 1;
                    }
                }
            }
          }
      }

      return dp[n - 1];
    }

    public static void main(String[] agrs){
        System.out.println( getMin("00000"));
        System.out.println( getMin("1111101"));
    }
}
//CutString .java 

