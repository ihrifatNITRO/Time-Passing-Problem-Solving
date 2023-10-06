#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// f(x) = x^3 - 6x^2 + 11x - 6 = 0

int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif

   //std::ios_base::sync_with_stdio(0);
   //cin.tie(NULL); cout.tie(NULL);

   int n = 3;
   double a[n] = {11/6.0 , -1.0 , 1/6.0};
   vector<double>b,ratio;
   b.push_back(1);
   b.push_back(a[0]);
   ratio.push_back(b[0] / b[1]);
   b.push_back(a[0]*b[1] + a[1]*b[0]);
   ratio.push_back(b[1] / b[2]);

   cout << ratio[ratio.size()-1] << " " << ratio[ratio.size()-2] << endl;
   int run = 10;
   while(run--){
   	  int p = 0, q = b.size() - 1;
   	  double x = 0;
   	  while(p < 3 && q >= 0){
   	  	x += a[p] * b[q];
   	  	p++;
   	  	q--;
   	  }
   	  b.push_back(x);
   	  ratio.push_back(b[b.size()-2] / b[b.size()-1]);
   	  cout << ratio[ratio.size()-1] << " " << ratio[ratio.size()-2] << endl;
   }

   cout << "Root = " << ratio[ratio.size() - 1];

   return 0;
}