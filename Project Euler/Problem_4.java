import java.util.*;


class B{
	public static int max(int x, int y){
		if(x > y)
			return x;
		return y;
	}
	public static boolean intPalindrome(int x){
		String s = Integer.toString(x);
		for(int a = 0, b = s.length() - 1; a <= b; a++, b--)
			if(s.charAt(a) != s.charAt(b))
				return false;
		return true;
	}
	
	public static void main(String args[]){
		int ans = -1;

		for(int a = 999; a > 99; a--){
			for(int b = 999; b > 99; b--)
				if(intPalindrome(a * b) == true)
					ans = max(ans, a * b);
		}

		System.out.println(ans);
	}
}