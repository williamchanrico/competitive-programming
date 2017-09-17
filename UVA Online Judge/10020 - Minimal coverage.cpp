#include <bits/stdc++.h>
using namespace std;

class Line{
public:
	int left;
	int right;
};

bool cmp(const Line &x, const Line &y){
	if(x.left == y.left)
		return x.right > y.right;
	return x.left < y.left;
}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		int M;
		Line line;
		vector<Line> v;

		scanf("%d", &M);

		while(scanf("%d %d", &line.left, &line.right), (line.left | line.right)){
			v.push_back(line);
		}

		sort(v.begin(), v.end(), cmp);

		int reached = 0;
		vector<Line> vAns;

		while(reached < M){
			int newReached = reached;
			int newLineIdx = -1;

			for(int a = 0; a < v.size(); a++){
				if(v[a].left > reached)
					break;

				if(v[a].right > newReached){
					newReached = v[a].right;
					newLineIdx = a;
				}
			}

			if(reached == newReached)
				break;

			reached = newReached;

			vAns.push_back(v[newLineIdx]);
		}

		if(reached < M){
			printf("0\n");
		}else{
			printf("%d\n", vAns.size());

			for(int a = 0; a < vAns.size(); a++)
				printf("%d %d\n", vAns[a].left, vAns[a].right);
		}

		printf("%s", (T == 0 ? "" : "\n"));
	}
}