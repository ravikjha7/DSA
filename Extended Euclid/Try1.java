import java.lang.*;
import java.util.*;
import java.io.*;

class Try1
{
	final static FastReader fr = new FastReader();
	final static PrintWriter out = new PrintWriter(System.out);

	static int add(int a,int b)
	{
		if(a > 3) return a+b;
	}

    static void solve()
    {
        int a = 5,b = 7;
        int c = add(a,b);
        out.println(c);
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