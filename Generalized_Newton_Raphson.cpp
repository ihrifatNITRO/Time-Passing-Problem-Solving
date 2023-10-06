
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// f(x) = x^3 - x^2 - x + 1
double equ(double x){
	return x*x*x - x*x - x + 1;
}
double equ_p(double x){
	return 3*x*x - 2*x - 1;
}
double equ_pp(double x){
	return 6*x - 2;
}


int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif

   //std::ios_base::sync_with_stdio(0);
   //cin.tie(NULL); cout.tie(NULL);

   int p = 3;
   double prev = 0.8, now = 0.8;

   for(p=3;p>1;p--){
   	  if(p == 3){
   	  	now = prev - (p-1) * (equ(prev) / equ_p(prev));
   	  }
   	  else{
   	  	now = prev - (p-1) * (equ_p(prev) / equ_pp(prev));
   	  }
   	  cout << "x = " << now << endl;
   	  prev = now;
   }

   cout << "Root = " << now << endl;

   return 0;
}