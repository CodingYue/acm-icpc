import java.io.*;
import java.util.*;
public class HashSetDemo {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
		HashSet<Long> hashset = new HashSet<Long>();
		for (String x = in.readLine(); x != null ; x = in.readLine())
			hashset.add( Long.parseLong(x) );
	} 
}
