public class ReverseWord {
    
    public boolean isSaperator(char c){
        if(c >= 'a' && c <= 'z'){
            return false;
        }
        if(c >= 'A' && c <= 'Z'){
            return false;
        }
        if(c >= '0' && c <= '9'){
            return false;
        }

        return true;
    }

    public void reverse(char[] working, int l, int r){
        while(l < r){
            char tmp = working[l];
            working[l] = working[r];
            working[r] = tmp;
            l++;
            r--;
        }
    }
    public String reverseWord(String str){
        char[] working = str.toCharArray();

        for(int i = 0; i < working.length; ){
            // eat white space
            while(i < working.length && isSaperator(working[i]) ){
                i++;
            }

            int frist = i;
            while(i < working.length && !isSaperator(working[i])){
                i++;
            }
            reverse(working, frist, i - 1);
        }

        return new String(working);
    }
    
    public static void main(String[] args){
        ReverseWord reverse = new ReverseWord(); 
        String str = "I am fool";
        System.out.println(reverse.reverseWord(str));
    }

}
