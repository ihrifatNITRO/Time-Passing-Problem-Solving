#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double equ(double x){
	return x*x*x - 2*x - 5;
}
double equ_prime(double x){
	return 3*x*x - 2;
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif


	double prev = 1;
	double now = prev - equ(prev)/equ_prime(prev);
	int cnt = 0;

	while(abs(now - prev) >= 0.0005){
		cnt++;
		cout << now << " ";
		prev = now;
		now = prev - equ(prev)/equ_prime(prev);
	}

	cout << "\n" << "Number of Iteration: " << cnt;
	return 0;

}