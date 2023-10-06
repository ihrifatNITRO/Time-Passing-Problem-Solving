#include<iostream>
#include<bits/stdc++.h>

using namespace std;



int main(){

	#ifndef ONLINE_JUDGE
	   freopen("input.txt", "r", stdin);
	   freopen("output.txt", "w", stdout);
	#endif

	double prev = 1;
	double now = sqrt((5/prev) + 2);
	int cnt = 0;

	while(abs(now - prev) >= 0.0005){
		cnt++;
		cout << now << " ";
		prev = now;
		now = sqrt((5/prev) + 2);
	}

	cout << "\n" << "Number of Iteration: " << cnt;
	return 0;
}
