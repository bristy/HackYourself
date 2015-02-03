import java.util.*;

public class FindPeakElement {
    public int findPeakElement(int[] num){
        int n = num.length;
        if(n == 1){
            return 0;
        }

        int lo = 0;
        int hi = n;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            long prev = mid - 1 >= 0 ? num[mid - 1] : Long.MIN_VALUE;
            long next = mid + 1 < n ? num[mid + 1] : Long.MIN_VALUE;
            // mid is peak
            if(num[mid] > prev && num[mid] > next){
                return mid;
            }

            if(prev < num[mid] && num[mid] < next){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
            
        }
        return lo;
    }

    public static void main(String[] args){
        FindPeakElement sol = new FindPeakElement();
        int A[] = {1, 2, 3, 1};
        System.out.println(sol.findPeakElement(A));
    }
}
