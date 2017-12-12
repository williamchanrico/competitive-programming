import java.util.*;
import java.math.*;


class Main{
  static Scanner sc = new Scanner(System.in);

  static final BigInteger TWENTY_SIX = BigInteger.valueOf(26);

  public static void main(String args[]){
  	while(true){

  		if(sc.hasNextBigInteger()){

  			BigInteger bigInt = sc.nextBigInteger();

  			System.out.printf("%-22s%s\n", convertToStr(bigInt), formatOutput(bigInt));

  		}else if(sc.hasNext()){

  			String str = sc.next();

  			if(str.equals("*")) break;

  			System.out.printf("%-22s%s\n", str, formatOutput(convertToNum(str)));
  			
  		}
  	}
  }

  public static String convertToStr(BigInteger x){
  	StringBuilder sb = new StringBuilder();

  	do{
  		sb.append((char) ('a' + x.subtract(BigInteger.ONE).mod(TWENTY_SIX).intValue()));

  		x = x.subtract(BigInteger.ONE).divide(TWENTY_SIX);
  	}while(x != BigInteger.ZERO);

  	return sb.reverse().toString();
  }

  public static BigInteger convertToNum(String x){
  	BigInteger bigInt = BigInteger.ZERO;

  	for(int a = 0; a < x.length(); a++){
  		bigInt = bigInt.multiply(TWENTY_SIX);
  		bigInt = bigInt.add(BigInteger.valueOf((int) (x.charAt(a) - 'a' + 1)));
  	}

  	return bigInt;
  }

  public static String formatOutput(BigInteger x){
  	String str = x.toString();
  	StringBuilder sb = new StringBuilder();

  	for(int a = str.length() - 1, b = 0; a >= 0; a--, b++){
  		sb.append(str.charAt(a));

  		if(a != 0 && b % 3 == 2)
  			sb.append(',');
  	}

  	return sb.reverse().toString();
  }
}