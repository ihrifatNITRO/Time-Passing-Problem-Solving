/* In the name of ALLAH */
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// equtions
// y^2 - 5*y + 4 = 0
// 3*y*x^2 - 10*x + 7 = 0

double xn(double x, double y){
	return (1/10.0)*((3*y*x*x)+7);
}

double yn(double x, double y){
	return (1/5.0)*((y*y)+4);
}

int main()
{
  #ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
  #endif

   //std::ios_base::sync_with_stdio(0);
   //cin.tie(NULL); cout.tie(NULL);

   double err = 0.001;
   double x = 0.5, y = 0.5;
   double x1 = xn(x,y);
   double y1 = yn(x,y);

   cout << x1 << " " << y1 << endl;
   while(abs(x1-x)>=err && abs(y1-y)>=err){
   		x = x1; y = y1;
   		x1 = xn(x,y);
   		y1 = yn(x,y);
   		cout << x1 << " " << y1 << endl;
   }

   return 0;
}