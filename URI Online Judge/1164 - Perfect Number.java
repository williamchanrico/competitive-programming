import java.util.Scanner;

class Main{
    public static void main(String args[]){
        Scanner inp = new Scanner(System.in);
        int T = inp.nextInt();
        while(T>0){
            int sum=0, n=inp.nextInt();
            for(int a=1;a<n;a++){
                if(n%a==0){
                    sum+=a;
                    if(sum>n){
                        break;
                    }
                }
            }
            if(sum==n)
                System.out.print(n+" eh perfeito\n");
            else
                System.out.print(n+" nao eh perfeito\n");
            T--;
        }
    }
}