/**
 * @author: Brajesh
 * ClimpStairs .java
 */ 

public class ClimpStairs {
    public ClimpStairs () {
    }

    int memo[];

    int solve(int n) {
        if(n < 0) {
            return 0;
        }
        if(n == 0) {
            memo[n] = 1;
            return memo[n];
        }
        if(memo[n] != Integer.MAX_VALUE){
            return memo[n];
        }
        memo[n] =  Math.min(solve(n - 1), solve(n - 2)) + 1;
        return memo[n];

    }

    int climbStairs(int n) {
       memo = new int[n + 1];
       for(int i = 0; i <= n; i++){
           memo[i] = Integer.MAX_VALUE;
       }
       return solve(n);
    }
    public static void main(String[] args) {
        ClimpStairs sol = new ClimpStairs();
        System.out.println(sol.climbStairs(3));
    }   
}
//ClimpStairs .java 

