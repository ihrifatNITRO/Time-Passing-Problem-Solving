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
   double x[n], y[n][n]= {0}; //y1[n-1], y2[n-2], y3[n-3], y4[n-4];
   foi(i,0,n) cin >> x[i] >> y[0][i];
   foi(i,1,n){
     foi(j,0,n-i){
       if(y[i-1][j+1] - y[i-1][j] >= 0.0001) y[i][j] = y[i-1][j+1] - y[i-1][j];
     }
   }

   cout << "x: ";
   foi(i,0,n) cout << x[i] << " ";
   cout << endl;
   foi(i,0,n-2){
     cout << "y" << i << ": ";
     foi(j,0,n){
       if(y[i][j]) cout << y[i][j] << " ";
     }
     cout << endl;
   }

   double h = abs(x[0] - x[1]);
   while(1){
     cout << "Enter 1 = Forward, 2 = Backward or >2 = Finish" << endl;
     int a; cin >> a; if(a > 2) return 0;
     double X; cin >> X; //desired value of x
     if(a == 1){
       double p[n-2]; p[0] = 1;
       p[1] = (X - x[n / 2]) / h;
       p[2] = p[1]*(p[1]-1);
       p[3] = (p[1]+1) * p[2];
       int r = 2;
       foi(i,4,n-2){
        p[i] = p[i-1] * (p[1] - r); r++;
       }
       double sum = 0;
       foi(i,0,n-2) sum += (y[i][(n-i)/2] * p[i]) / fact(i);
       cout << "y(" << X << ") = " << sum << endl;
     }
     else if(a == 2){
       double p[n-2]; p[0] = 1;
       p[1] = (X - x[n / 2]) / h;
       p[2] = p[1]*(p[1]+1);
       p[3] = (p[1]-1) * p[2];
       int r = 2;
       foi(i,4,n-2){
        p[i] = p[i-1] * (p[1] + r); r++;
       }
       double sum = 0;
       foi(i,0,n-2) sum += (y[i][(n-i)/2] * p[i]) / fact(i);
       cout << "y(" << X << ") = " << sum << endl;
     }
   }
   
}