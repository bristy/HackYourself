package codemonk.searching;

import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * Created by brajesh.k on 26/06/16.
 */
public class SearchingUtils {
    public static <T> int linearSearch(List<T> collection, T value) {
        if (collection != null && value != null) {
            for (int index = 0; index < collection.size(); index++) {
                if (collection.get(index).equals(value)) {
                    return index;
                }

            }
        }
        return -1;
    }

    public static <T> int linearSearch(T[] collection, T value) {
        if (collection != null && value != null) {
            for (int index = 0; index < collection.length; index++) {
                if (collection[index].equals(value)) {
                    return index;
                }

            }
        }
        return -1;
    }


}
