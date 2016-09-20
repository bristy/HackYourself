package StringArray;

/**
 * Created by brajesh.k on 21/09/16.
 */
public class RunLengthEncoding {
    public static int inPlace(char[] str) {
        if (str == null ) {
            return -1;
        }

        int n = str.length;
        if (n == 1) {
            return -1;
        }
        int k = 0;
        int bp = 0;
        char[] buffer = new char[n - 1]; // allowed buffer (n - 1) bytes
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i + 1 < n && str[i] == str[i + 1]) {
                count++;
                i++;
            }

            // fill char to buffer
            buffer[bp++] = str[i];

            // fill count to buffer
            while (bp < n - 1 && count > 0) {
                buffer[bp++] = (char) (count % 10 + '0');
                count /= 10;
            }

            // if buffer was not sufficient return with error code -1
            if (count > 1 || bp > n - 1) {
                return -1;
            }

            // check if you can flush buffer to input string
            if (k + bp - 1 <= i) {
                for (int j = 0; j < bp; j++) {
                    str[k] = buffer[j];
                    k++;
                }
                bp = 0;
            }
        }

        // print encoded string
        for (int i = 0; i < k; i++) {
            System.out.print(str[i]);
        }
        System.out.println();
        return k;
    }

    public static void main(String[] args) {
        inPlace("geekkkk".toCharArray());
    }

}
