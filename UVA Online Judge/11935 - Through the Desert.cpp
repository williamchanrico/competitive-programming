#include <bits/stdc++.h>

#define INF 1000000000
#define EPS 1e-9

std::vector<std::string> v;

bool survive(double maxFuel){
	std::string inputString;
	int inputNumber;
	int pos = 0;
	int leak = 0;
	int goal = INF;
	int consumption = 0;
	double fuel = maxFuel;

	for(int a = 0, len = v.size(); a < len; a++){
		std::stringstream ss(v[a]);
		ss >> inputNumber >> inputString;

		int delta = inputNumber - pos;

		fuel -= (consumption * delta / 100.0) + (leak * delta);
		
		if(fuel < 0) return false;
		
		pos = inputNumber;

		if(inputString == "Goal") return true;
		else if(inputString == "Leak") leak++;
		else if(inputString == "Mechanic") leak = 0;
		else if(inputString == "Gas") fuel = maxFuel;
		else if(inputString == "Fuel") ss >> inputString >> consumption;
	}
}

int main(){
	// freopen("in.txt", "r", stdin);
	std::string inputString;

	while(true){
		getline(std::cin, inputString);
		
		if(v.size() == 0 && inputString == "0 Fuel consumption 0") break;

		v.push_back(inputString);
		
		if(inputString.find("Goal") != std::string::npos){
			double lo = 0.000;
			double hi = 10000.000;
			double mid;
			double ans;

			while(fabs(lo - hi) > EPS){
				mid = (lo + hi) / 2.0;
				if(survive(mid)) ans = hi = mid;				
				else lo = mid;
			}

			std::cout << std::fixed << std::setprecision(3) << ans << "\n";

			v.clear();
		}
	}
}