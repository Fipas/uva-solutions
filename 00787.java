import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main {

	public static void main (String args[])  
	{
		Scanner sc = new Scanner(System.in);
		String line;

		while (sc.hasNext()) {
			line = sc.next();
			ArrayList<BigInteger> numbers = new ArrayList<BigInteger>();
			
			while (!line.equals("-999999")) {
				numbers.add(new BigInteger(line));
				line = "-999999";
				if (sc.hasNext())
					line = sc.next();
			}
			
			BigInteger ans = new BigInteger("-999999");
			
			for (int i = 0; i < numbers.size(); i++) {
				BigInteger sum = new BigInteger(numbers.get(i).toString());
				if (ans.compareTo(sum) == -1)
					ans = new BigInteger(sum.toString());
				for (int j = i + 1; j < numbers.size(); j++) {
					sum = sum.multiply(numbers.get(j));
					if (ans.compareTo(sum) == -1)
						ans = new BigInteger(sum.toString());
				}
			}
			
			System.out.println(ans);			
		}
	}
}