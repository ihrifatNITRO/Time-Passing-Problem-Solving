#include<bits/stdc++.h>
#define foi(i,n)  for(int i=0;i<n;i++)


using namespace std;

int fact(int x){
    if(x == 0) return 1;
    else return x*fact(x-1);
}

int main(){

	#ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif

    int n; cout << "Enter data size: ";
    cin >> n;
    int x[n],y[n],dy[n-1],ddy[n-2],dddy[n-3];
    cout << "Enter values of x and y: " << "\n";
    foi(i,n) cin >> x[i] >> y[i];
    foi(i,n-1) dy[i] = y[i+1] - y[i];
    foi(i,n-2) ddy[i] = dy[i+1] - dy[i];
    foi(i,n-3) dddy[i] = ddy[i+1] - ddy[i];
    cout << "\n" << "Data table: ";
    cout << "\n" << "x: "; foi(i,n) cout << x[i] << " ";
    cout << "\n" << "y: "; foi(i,n) cout << y[i] << " ";
    cout << "\n" << "dy: "; foi(i,n-1) cout << dy[i] << " ";
    cout << "\n" << "ddy: "; foi(i,n-2) cout << ddy[i] << " ";
    cout << "\n" << "dddy: "; foi(i,n-3) cout << dddy[i] << " ";
    cout << "\n\n";

    double h = x[1] - x[0];
    while(1){
    	int click; cout << "Type 1 or 2 or 3: ";
    	cin >> click;
    	if(click == 1){
    		cout << "Forward Interpolation" << "\n" << "Enter your desired value of x: ";
    		double xn; cin >> xn; double p[n-1]; p[0] = (xn - x[0]) / h;
    		for(int i=1;i<n-1;i++) p[i] = p[i-1] * (p[0] - i);
    		int Y[n] = {y[0] , dy[0] , ddy[0] , dddy[0]};
    		double sum = Y[0] * 1.0;
    		for(int i=1;i<n;i++) sum += (p[i-1] * Y[i]) / fact(i);
    		cout << "y("<<xn<<") = " << sum << "\n\n";
    	}
    	else if(click == 2){
    		cout << "Backward Interpolation" << "\n" << "Enter your desired value of x: ";
    		double xn; cin >> xn; double p[n-1]; p[0] = (xn - x[n-1]) / h;
    		for(int i=1;i<n-1;i++) p[i] = p[i-1] * (p[0] + i);
    		int Y[n] = {y[n-1] , dy[n-2] , ddy[n-3] , dddy[n-4]};
    		double sum = Y[0] * 1.0;
    		for(int i=1;i<n;i++) sum += (p[i-1] * Y[i]) / fact(i);
    		cout << "y("<<xn<<") = " << sum << "\n\n";
    	}
    	else{cout << "Terminated!!!" << endl; return 0;}
    }
}