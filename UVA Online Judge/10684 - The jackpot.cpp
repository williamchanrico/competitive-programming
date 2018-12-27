#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    while (scanf("%d", &N) && N != 0) {
        int inp;
        int sum = 0;
        int maxSum = 0;

        for (int a = 0; a < N; a++) {
            scanf("%d", &inp);

            sum += inp;
            sum = (sum < 0 ? 0 : sum);

            maxSum = max(maxSum, sum);
        }

        if (maxSum > 0)
            printf("The maximum winning streak is %d.\n", maxSum);
        else
            printf("Losing streak.\n");
    }
}

/* another form of Kadane's algorithm
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	
	while(scanf("%d", &N) && N != 0){
		int arr[10000 + 10];
		int sum = 0;
		int maxSum = 0;

		for(int a = 0; a < N; a++){
			scanf("%d", &arr[a]);
		}

		for(int a = 0; a < N; a++){
			sum = max(sum + arr[a], 0);
			maxSum = max(maxSum, sum);
		}

		if(maxSum > 0)
			printf("The maximum winning streak is %d.\n", maxSum);
		else
			printf("Losing streak.\n");
	}
}
*/