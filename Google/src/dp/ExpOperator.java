package dp;

import java.util.*;

/**
 * Created by brajesh.k on 21/10/16.
 */

public class ExpOperator {

    public static void main(String[] args) {
        List<String> ret = new ExpOperator().addOperators("105", 5);
        System.out.println(ret);
    }

    Map<String, Integer> memo = new HashMap<>();
    public List<String> addOperators(String num, int target) {
        List<String> ret = new ArrayList<>();
        if(num.length() == 0) {

        } else if(num.length() == 1) {
            int val = Integer.parseInt(num);
            if(val == target) {
                ret.add(num);
            }

        } else {
            solve(num, "", target, ret);
        }
        return ret;
    }

    private void solve(String num, String soFar,  int target, List<String> ret) {
        if(num.length() == 0) {
            int val = eval(soFar);
            if(val == target) {
                ret.add(soFar);
            }
            return;
        }

        if(soFar.length() > 0) {
            for (char c : "*-+".toCharArray()) {
                solve(num.substring(1), soFar + String.valueOf(c) + String.valueOf(num.charAt(0)), target, ret);
            }
        }
        if(soFar.length() == 0 || (soFar.charAt(soFar.length() - 1) != '0')) {
            solve(num.substring(1), soFar + String.valueOf(num.charAt(0)), target, ret);
        }

    }

    public int eval(String s) { // assumes s is valid expression

        if (memo.get(s) != null) {
            return memo.get(s);
        }
        if(s.indexOf("*") == -1 && s.indexOf("+") == -1 && s.indexOf("-") == -1) {
            memo.put(s, Integer.parseInt(s));
            return memo.get(s);
        }


        Stack<String> stack = new Stack<>();
        char[] exp = s.toCharArray();
        String prev = "";
        for(char c : exp) {
            if(c == '*' || c == '-' || c == '+') {
                stack.push(prev);
                stack.push(String.valueOf(c));
                prev = "";
            }  else {
                prev += String.valueOf(c);
            }
        }
        stack.push(prev);

        Stack<String> aux = new Stack<>();
        while(!stack.isEmpty()) {
            String c = stack.pop();
            if("*".equals(c)) {
                int val = Integer.parseInt(stack.pop());
                int curr = Integer.parseInt(aux.pop());
                aux.push(String.valueOf(val * curr));
            } else {
                aux.push(c);
            }
        }
        int ret = Integer.parseInt(aux.pop());
        while(!aux.isEmpty()) {
            String c = aux.pop();
            if("+".equals(c)) {
                ret += Integer.parseInt(aux.pop());
            } else if("-".equals(c)){
                ret -= Integer.parseInt(aux.pop());
            }
        }
        memo.put(s, ret);
        return ret;
    }


}