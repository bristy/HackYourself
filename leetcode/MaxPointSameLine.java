import java.util.*;
import java.lang.*;
public class MaxPointSameLine {
    public int maxPoints(Point[] points) {
        
        
        int result = 0;
        for(int i = 0; i<points.length; i++){
            Map<Double, Integer> line = new HashMap<Double, Integer>();
            Point a = points[i];
            int same = 1;    
            //System.out.println(a);
            for(int j = i+1; j<points.length; j++){
                Point b = points[j];
                //System.out.println(" point " + b.toString());
                if(a.x == b.x && a.y == b.y){
                    same++;
                } else {
                    double dy = b.y - a.y;
                    double dx = b.x - a.x;
                    Double slope;
                    if(dy == 0){ // horizontal
                        slope = 0.0;
                    } else if(dx == 0){//eartical
                        slope = Math.PI/2;
                    } else {
                        slope = Math.atan(dy/dx);
                    }
                    Integer slopeVal = line.get(slope);
                    //System.out.println(" slope " + slope + "  slope value " + slopeVal);
                    if(slopeVal == null){
                        slopeVal = 1;
                    } else {
                        slopeVal += 1;
                    }
                    line.put(slope, slopeVal);
                }
            }
            
            for (Double key : line.keySet()) {
				Integer val = line.get(key);
				result = Math.max(result, val + same);
			}
			// for all points are same
			result = Math.max(result, same);
            
        }
        return result;
    }
    
    
    public static void main(String[] args){
        Point[] points = new Point[]{
            new Point(2,3),
                new Point(3,3),
                new Point(-5,3)
        };
        System.out.println(new MaxPointSameLine().maxPoints(points));
    }
}

 class Point{
    int x;
    int y;
    Point(){
        x = 0;
        y = 0;
    }

    Point(int a, int b){
        x = a;
        y = b;
    }

    @Override
    public String toString(){
        return "x " + x + " y " + y;
    }
}


