import java.util.*;

public class MergeSortedArray{
    public void merge(int A[], int m, int B[], int n){
        int idx = m + n - 1;
        m--;
        n--;
        while(m >= 0 && n >= 0){
            if(A[m] > B[n]){
                A[idx--] = A[m--];
            } else {
                A[idx--] = B[n--];
            }
        }

        while(n >=0 ){
            A[idx--] = B[n--];
        }
    }
}
