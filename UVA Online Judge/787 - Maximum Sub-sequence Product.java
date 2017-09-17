import java.util.*;
import java.math.*;

class Main {
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> arr = new ArrayList<Integer>();

		while(sc.hasNext()){
			int inp = sc.nextInt();

			if(inp == -999999){
				BigInteger maxProd = BigInteger.valueOf(arr.get(0));

				for(int a = 0; a < arr.size(); a++){
					BigInteger prod = BigInteger.ONE;

					for(int b = a; b < arr.size(); b++){
						prod = prod.multiply(BigInteger.valueOf(arr.get(b)));
						maxProd = maxProd.max(prod);
					}
				}

				System.out.println(maxProd);

				arr.clear();

				continue;
			}

			arr.add(inp);
		}
	}
}