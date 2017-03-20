#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, type, l, r;
long long temp, sum=0;
vector<long long> v1, v2;

long long kerja(int type, int l, int r){
	if(type==1) return v1[r]-((l-1)>=0?v1[l-1]:0);
	else return v2[r]-((l-1)>=0?v2[l-1]:0);
}

bool cmp(long long x, long long y){ return x<y; }

int main(){
	scanf("%d", &n);
	for(int a=0;a<(int)n;a++){
		cin >> temp;
		sum+=temp;
		v1.push_back(sum);
		v2.push_back(temp);
	}
	sum=0;
	sort(v2.begin(), v2.end(), cmp); 
	for(int a=0;a<n;a++){
		sum+=v2[a];
		v2[a]=sum;
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		scanf("%d %d %d", &type, &l, &r);
		printf("%lld\n", kerja(type, l-1, r-1));
	}
}