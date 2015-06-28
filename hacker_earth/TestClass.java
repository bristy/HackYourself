/* IMPORTANT: class must not be public. */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

class TestClass {
    static BufferedReader br;
	public static Map<ArrayList<Integer>, String> getDinosaurs(int N, int K, int L) throws IOException{
		Map<ArrayList<Integer>, String> map = new HashMap<ArrayList<Integer>, String>();
		//Scanner sc = new Scanner(System.in);
		for (int i = 1; i <= N; i++) {
			String[] lines = br.readLine().split(" ");
            String diana = lines[0];
		    //System.out.println("diana = " + diana);

            ArrayList<Integer> list = new ArrayList<Integer>();
			for (int j = 1; j <= K; j++) {
				//System.out.println("Enter attribute");
				list.add(Integer.parseInt(lines[j]));
			}
			//System.out.println("Enter dinosaurs Name");
			map.put(list, diana);
		}
		return map;
	}

	public static void getOutput(Map<ArrayList<Integer>, String> result, int K, int Q) throws IOException{
		int flag = 1;
		List<ArrayList<Integer>> option = new ArrayList<ArrayList<Integer>>();
		//sc = new Scanner(System.in);
		for (int n = 1; n <= Q; n++) {
            String[] lines = br.readLine().split(" ");
			ArrayList<Integer> val = new ArrayList<Integer>();
			for (int i = 0; i < K; i++) {
				//System.out.println("Enter options");
				val.add(Integer.parseInt(lines[i]));
			}
            //System.out.println(val);
			option.add(val);
		}

		for (ArrayList<Integer> temp : option) {
			String ret = result.get(temp);
			if(ret != null) {
				System.out.println(ret);
				flag = 1;
			} else {
				flag = 0;
			}
//			for (Entry<ArrayList<Integer>, String> entry : result.entrySet()) {
//
//				List<Integer> values = entry.getKey();
//
//				if (values.equals(temp)) {
//					System.out.println(entry.getValue());
//					flag = 1;
//					break;
//				} else {
//					flag = 0;
//				}
//
//			}
			if (flag == 0){
				System.out.println("You cant fool me :P");
			}
		}

	}

	public static void main(String args[]) throws IOException{
		int N = 0, K = 0, L = 0, Q = 0;
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] lines = br.readLine().split(" ");
		//System.out.println("Enter number of dinosaurs");
		N = Integer.parseInt(lines[0]);
		K = Integer.parseInt(lines[1]);
        L = Integer.parseInt(lines[2]);
        Q = Integer.parseInt(lines[3]);
		Map<ArrayList<Integer>, String> result = getDinosaurs(N, K, L);
		getOutput(result, K, Q);

	}
}
