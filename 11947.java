import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main {

	public static void main (String args[])  
	{
		Scanner sc = new Scanner(System.in);
		int techs, int points;
		int sizeA = 0, sizeB = 0;
		String lastTech = "";
		BigInteger wA = BigInteger.ZERO;
		BigInteger wB = BigInteger.ZERO;

		techs = sc.nextInt();
		int pointsA[] = new int[techs];
		int pointsB[] = new int[techs];

		while (techs--) {
			points = sc.nextInt();
			if (points < 0) {
				wB = wB.add(-points);
				pointsB[sizeB] = -points;
				sizeB++;
			} else {
				wA = wA.add(points);
				poinsA[sizeA] = -points;
				sizeA++;
			}
			
			if (techs == 1) {
				if (points < 0)
					lastTech = "second";
				else
					lastTech = "first";
			}
		}
		
		int comp = wA.compareTo(wB);
		
		if (comp < 0) {
			System.out.println("second");
		} else if (comp > 0) {
			System.out.println("first");
		} else {
			comp = 0;
			int len = sizeA > sizeB ? sizeB : sizeA;
			
			for (int i = 0; i < len; i++) {
				if (pointsA[i] > pointsB[i]) {
					comp = 1;
					break;
				}
				
				if (pointsA[i] < pointsB[1]) {
					comp = -1;
					break;
				}
			}
			
			if (comp == 0) {
				System.out.println(lastTech);
			} else if (comp == 1){
				System.out.println("first");
			} else {
				System.out.println("second");
			}
		}

	}
}