import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Created by brajesh.k on 28/10/16.
 */

// Definition for an interval.
class Interval {
    int start;
    int end;

    Interval() {
        start = 0;
        end = 0;
    }

    Interval(int s, int e) {
        start = s;
        end = e;
    }
}

public class MeetingRooms2 {
    public int minMeetingRooms(Interval[] intervals) {
        PriorityQueue<Interval> pq = new PriorityQueue<Interval>(8, new Comparator<Interval>() {
            @Override
            public int compare(Interval a, Interval b) {
                if (a.end != b.end) {
                    return a.end - b.end;
                } else {
                    return a.start - b.start;
                }
            }
        });
        Arrays.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval a, Interval b) {
                if (a.start != b.start) {
                    return a.start - b.start;
                } else {
                    return a.end - b.end;
                }

            }
        });
        int ret = 0;
        for (Interval interval : intervals) {
            int size = pq.size();
            while (size > 0) {
                Interval top = pq.peek();
                if (top.end < interval.start) {
                    pq.poll();
                    size--;
                } else {
                    break;
                }
            }
            pq.add(interval);
            ret = Math.max(ret, pq.size());
        }
        return ret;
    }
}