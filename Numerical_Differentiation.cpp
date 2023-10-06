/* In the name of ALLAH */
#include<bits/stdc++.h>

#define foi(i,a,n)      for(int i=a;i<n;i++)
#define fast  std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int fact(int n){
  if(n == 0) return 1;
  return n * fact(n-1);
}

int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif

   fast

   cout << "Enter Data Size: ";
   int n; cin >> n;
   cout << "Enter Data of x and y: ";
   double x[n], y[n][n]= {0};
   foi(i,0,n){
    cin >> x[i] >> y[0][i];
   }
   foi(i,1,n){
     foi(j,0,n-i){
       if(y[i-1][j+1] - y[i-1][j] >= 0.0001) y[i][j] = y[i-1][j+1] - y[i-1][j];
     }
   }

   cout << "x: ";
   foi(i,0,n) cout << x[i] << " ";
   cout << endl;
   foi(i,0,n-1){
     cout << "y" << i << ": ";
     foi(j,0,n){
       if(y[i][j]) cout << y[i][j] << " ";
     }
     cout << endl;
   }

   cout << "Enter your desired value of X: ";
   double X; cin >> X;
   double h = x[1] - x[0];
   if(abs(x[n-1]-X) >= abs(x[0]-X)){
       cout << "Forward Differentiation Formula" << endl;
       int ind; foi(i,0,n) if(x[i] == X) ind = i;
       double dydx = 0, dyydxx = 0;
       foi(i,1,n){
        if(i%2) dydx += y[i][ind] / i;
        else dydx -= y[i][ind] / i;
       }
       dyydxx = y[2][ind] - y[3][ind] + (11/12.0)*y[4][ind] - (5/6.0)*y[5][ind];
       cout << "First Differentiation: " << dydx / h << endl;
       cout << "Second Differentiation: " << dyydxx / (h*h) << endl;
   }
   else{
       cout << "Backward Differentiation Formula" << endl;
       int ind; foi(i,0,n) if(x[i] == X) ind = i - 1;
       double dydx = y[1][ind], dyydxx = 0;
       foi(i,2,n) dydx += y[i][ind] / i;
       dyydxx = y[2][ind] + y[3][ind] + (11/12.0)*y[4][ind] + (5/6.0)*y[5][ind];
       cout << "First Differentiation: " << dydx / h << endl;
       cout << "Second Differentiation: " << dyydxx / (h*h) << endl;
   }
   
   return 0;
   
}