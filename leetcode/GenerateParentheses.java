import java.util.*;
public class GenerateParentheses{
    public List<String> generateParenthesis(int n){
        List<String> paren = new ArrayList<String>();
        generateParenthesis("", paren, 2 * n, 0);
        return paren; 
    }

    private void generateParenthesis(String currString, List<String> paren, int n, int balance){
        if(balance < 0){
            return ;
        }
        if(n == 0){
            if(balance == 0){
                paren.add(currString);
            }
            return;
        }

        generateParenthesis(currString + ")", paren, n - 1, balance - 1);
        generateParenthesis(currString + "(", paren, n - 1, balance + 1);
    }
    public static void main(String[] args){
        GenerateParentheses sol = new GenerateParentheses();
        System.out.println(sol.generateParenthesis(3));
    }
}
