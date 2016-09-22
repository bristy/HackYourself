package StringArray;

import utils.Pair;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * Created by brajesh.k on 21/09/16.
 */
public class ConflictingEvents {
    public static List<Pair> getConflictingEvents(List<Pair> events) {
        List<Pair> result = new ArrayList<>();
        if (events == null || events.size() == 1) {
            return result;
        }
        Collections.sort(events, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.second != o2.second) {
                    return o1.second.compareTo(o2.second);
                } else {
                    return o1.first.compareTo(o2.first);
                }
            }
        });
        if (events.get(1).first < events.get(0).second) {
            result.add(events.get(0));
        }
        for (int i = 1; i < events.size(); i++) {
            if (events.get(i).first < events.get(i - 1).second) {
                result.add(events.get(i));
            }
        }
        return result;
    }

    public static class Pair {
        Integer first;
        Integer second;

        public Pair(Integer first, Integer second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public String toString() {
            return String.format("(%s, %s)", first, second);
        }
    }

    public static void main(String[] args) {
        List<Pair> events = new ArrayList<>();
        events.add(new Pair(2, 5));
        events.add(new Pair(1, 10));
        events.add(new Pair(7, 11));
        events.add(new Pair(13, 20));

        List<Pair> conflicts = getConflictingEvents(events);
        for (Pair event : conflicts) {
            System.out.println(event);
        }
    }
}
