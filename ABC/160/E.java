import java.io.*;
import java.util.PriorityQueue;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int x = Integer.parseInt(line[0]);
        int y = Integer.parseInt(line[1]);
        int a = Integer.parseInt(line[2]);
        int b = Integer.parseInt(line[3]);
        int c = Integer.parseInt(line[4]);
        PriorityQueue<Integer> p = new PriorityQueue<Integer>(a);
        PriorityQueue<Integer> q = new PriorityQueue<Integer>(b);
        PriorityQueue<Integer> r = new PriorityQueue<Integer>(c, (v1, v2)->v2-v1);
        line = br.readLine().split(" ");
        for(int i = 0; i < a; i++)  p.add(Integer.parseInt(line[i]));
        line = br.readLine().split(" ");
        for(int i = 0; i < b; i++)  q.add(Integer.parseInt(line[i]));
        line = br.readLine().split(" ");
        for(int i = 0; i < c; i++)  r.add(Integer.parseInt(line[i]));
        while(p.size() > x) p.poll();
        while(q.size() > y) q.poll();
        while(!r.isEmpty() && (p.peek() < r.peek() || q.peek() < r.peek())){
            if(p.peek() < q.peek()){
                p.poll();
                p.add(r.poll());
            }else{
                q.poll();
                q.add(r.poll());
            }
        }
        long ans = 0;
        for(int val : p)    ans += val;
        for(int val : q)    ans += val;
        System.out.println(ans);
    }
}
