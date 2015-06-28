public class FactTrailingZero {
  public int trailingZeros(int n){
    long base = 5;
    int ret = 0;
    while(n / base > 0){
      ret += (n / base);
      base *= 5;
    }

    return ret;
  }
  public static void main(String[] args){
    System.out.print(new FactTrailingZero().trailingZeros(20));
  }
}
