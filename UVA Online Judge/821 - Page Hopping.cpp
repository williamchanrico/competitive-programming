#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int N, R, AdjMat[110][110];

int main(){
	int x, y, Case=1;
	while(scanf("%d %d", &x, &y), x||y){
		for(int a=0;a<101;a++)
			for(int b=0;b<101;b++)
				AdjMat[a][b]=INF;
		AdjMat[x][y]=1;
		int maks=-1;
		while(scanf("%d %d", &x, &y), x||y){
			AdjMat[x][y]=1; maks=max(maks, x); maks=max(maks, y);
		}
		for(int a=0;a<=maks;a++)
			for(int b=0;b<=maks;b++)
				for(int c=0;c<=maks;c++)
					AdjMat[b][c]=min(AdjMat[b][c], AdjMat[b][a]+AdjMat[a][c]);
		int div=0, ans=0;
		for(int a=0;a<=maks;a++)
			for(int b=0;b<=maks;b++)
				if(AdjMat[a][b]!=INF && a!=b){
					div++;
					ans+=AdjMat[a][b];
				}
		printf("Case %d: average length between pages = %.3lf clicks\n", Case++, (1.0*ans)/div);
	}
}