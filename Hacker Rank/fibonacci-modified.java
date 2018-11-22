import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the fibonacciModified function below.
    static String fibonacciModified(int t1, int t2, int n) {
        BigInteger bTemp = BigInteger.valueOf(0);
        BigInteger bT1 = BigInteger.valueOf(t1);
        BigInteger bT2 = BigInteger.valueOf(t2);

    	for(int a = 2; a < n; a++){
    		bTemp = bT1.add(bT2.pow(2));
    		bT1 = bT2;
    		bT2 = bTemp;
    	}

    	return bTemp.toString();
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] t1T2n = scanner.nextLine().split(" ");

        int t1 = Integer.parseInt(t1T2n[0]);

        int t2 = Integer.parseInt(t1T2n[1]);

        int n = Integer.parseInt(t1T2n[2]);

        String result = fibonacciModified(t1, t2, n);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

