#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		int B, SG, SB, inp;

		scanf("%d %d %d", &B, &SG, &SB);

		priority_queue<int> pqG, pqB;

		for(int a = 0; a < SG; a++){
			scanf("%d", &inp);

			pqG.push(inp);
		}

		for(int a = 0; a < SB; a++){
			scanf("%d", &inp);

			pqB.push(inp);
		}

		while(!pqG.empty() && !pqB.empty()){
			vector<int> battle;

			for(int a = 0; a < B; a++){
				if(pqG.empty() || pqB.empty())
					break;

				battle.push_back(pqG.top() - pqB.top());
				
				pqG.pop();
				pqB.pop();
			}

			for(int a = 0; a < battle.size(); a++)
				if(battle[a] > 0)
					pqG.push(battle[a]);
				else if(battle[a] < 0)
					pqB.push(-battle[a]);
		}

		if(pqG.empty() && pqB.empty()){

			printf("green and blue died\n");

		}else if(pqB.empty()){

			printf("green wins\n");

			while(!pqG.empty()){
				printf("%d\n", pqG.top());

				pqG.pop();
			}

		}else{

			printf("blue wins\n");

			while(!pqB.empty()){
				printf("%d\n", pqB.top());

				pqB.pop();
			}

		}

		if(T)
			printf("\n");
	}
}
