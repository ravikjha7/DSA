import java.lang.*;
import java.util.*;
import java.io.*;

class Test
{
	final static FastReader fr = new FastReader();
	final static PrintWriter out = new PrintWriter(System.out);

    static void solve()
    {
        int n = fr.nextInt();

        long[] arr = new long[n];
        long[] brr = new long[n];

        for(int i = 0; i < n; i++)
        {
        	arr[i] = fr.nextLong();
        }
        long max = 0;
        for(int i = 0; i < n; i++)
        {
        	brr[i] = fr.nextLong();
        	max = Math.max(brr[i],max);
        }

        List<List<Integer>> m = new ArrayList<>();
        for(int i = 0; i <= max; i++)
        {
        	m.add(new ArrayList<>());
        }


        for(int i = 0; i < n; i++)
        {
        	m.get((int)brr[i]).add(i);
        }

        PriorityQueue<Long> pq = new PriorityQueue<>((p1,p2)->{
        	if(arr[Math.toIntExact(p1)] > arr[Math.toIntExact(p2)]) return -1;
        	return 1;
        });

        for(long x : m.get(0)) {
        	pq.add(x);
        }
        double s = 0.0;
        double a = 0.0;
        int pos = 0;
        for(int i = 0; i < n && pq.size() > 0; i++)
        {
        	s += arr[Math.toIntExact(pq.poll())];

        	a = Math.max(a,s/(i+1));
        	pos++;

        	if(pos < m.size())
        	{
        		for(long x : m.get(pos)) pq.add(x);
        	}
        }
        out.println(a);
    }
	public static void main(String[] args)
	{
		int t = fr.nextInt();
        while(t-- > 0)
        {
            solve();
        }
        out.close();
	}

	static class FastReader 
	{
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}