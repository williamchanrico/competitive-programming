#include <bits/stdc++.h>
using namespace std;

int X, N, K, Q;
char inp[20];
vector<int> v;

int main(){
	scanf("Subsoal %d", &X);
	scanf("%d %d %d", &N, &K, &Q);
	if(X==0){ printf("3 2 5 6\n"); return 0; }
	if(X==5){
		int hi=N, lo=1, mid, past;
		while(true){
			mid=(hi+lo)/2;
			if(past==mid) break;
			printf("1 %d\n", mid);
			fflush(stdout);
			scanf("%s", inp);
			if(inp[0]=='b'){
				lo=mid+1;
			}else{
				hi=mid-1;
			}
			past=mid;
		}
		printf("%d", mid);
		for(int a=1;a<=mid;a++)
			printf(" %d", a);
		printf("\n");
		fflush(stdout);
		scanf("%s", inp);
		return 0;
	}
	if(K==1){
		for(int a=1;a<=N;a++){
			printf("1 %d\n", a);
			fflush(stdout);
			scanf("%s", inp);
			if(inp[0]=='b') v.push_back(a);
			if(inp[0]=='y') return 0;
		}
		printf("%d", v.size());
		for(int a=0;a<v.size();a++)
			if(a==v.size()) printf(" %d\n", v[a]);
			else printf(" %d", v[a]);
		printf("\n");
		fflush(stdout);
		scanf("%s", inp);
		return 0;
	}else if(K==2){
		bitset<1010> bs; bs.set();
		for(int a=1;a<=N;a++)
			for(int b=a+1;b<=N;b++){
				printf("2 %d %d\n", a, b);
				fflush(stdout);
				scanf("%s", inp);
				if(inp[0]=='t'){ bs[a]=0; bs[b]=0; }
			}
		for(int a=1;a<=N;a++)
			if(bs[a]) v.push_back(a);
		printf("%d", v.size());
		for(int a=0;a<v.size();a++)
			if(a==v.size()-1) printf(" %d\n", v[a]);
			else printf(" %d", v[a]);
		fflush(stdout);
		scanf("%s", inp);
		if(inp[0]!='y'){
			for(int a=0;a<v.size();a++){
				printf("%d", v.size()-1);
				for(int b=0;b<v.size();b++)
					if(v[b]!=v[a]) printf(" %d", v[b]);
				printf("\n");
				fflush(stdout);
				scanf("%s", inp);
				if(inp[0]=='y') return 0;
			}
		}
		return 0;
	}
}