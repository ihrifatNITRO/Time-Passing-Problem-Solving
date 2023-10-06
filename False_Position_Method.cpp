
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// for finding value of a and b
double equ(double x){
	return x*x*x-2*x-5;
}


int main(){

	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	double a=0, b=0;
	int i=0;
	// passing some int to get values of a and b
	while(a >= b || equ(a)*equ(b) >= 0){
		double d = (double)i;

		if(equ(d) < 0) a = d;
		else b = d;
		if(d!=0){
			if(equ((-1)*d) < 0) a = (-1)*d;
			else b = (-1)*d;
		}

		i++;
	}

	vector<double>v; // to store values of x
	double x = (a*equ(b) - b*equ(a)) / (equ(b)-equ(a));

	// main process
	double abs_err = 0.0005;
	int j = 0;
	while(1){
		v.push_back(x); // keeping values of x

		// checking if x is the root
		if(equ(x) == 0) break;

		// changing the values of a or b
		if(equ(a)*equ(x) < 0) b = x;
		else a = x;

		// re-assigning values of x
		x = (a*equ(b) - b*equ(a)) / (equ(b)-equ(a));

		// checking differences
		if(j > 0 && abs(v[j]-v[j-1]) < abs_err) break;

		j++;
	}


	cout << "Number of iteration of False Position Method = " << j+1;

	
	return 0;
}

