#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v;

int main(){
	int temp;
	while(scanf("%d", &temp)!=EOF)
		v.push_back(temp);
	for(int a=v.size()-1;a>-1;a--)
		printf("%d\n", v[a]);
}
