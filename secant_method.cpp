// In the name of Allah
#include<bits/stdc++.h>
#include<iostream>
#define foi(i,n) for(int i=0;i<n;i++)

using namespace std;

double equ(double x){
    return x*x*x - 2*x - 5;
}
double get_x(double first, double second){
    double x = (first*equ(second) - second*equ(first)) / (equ(second) - equ(first));
    return x;
}


int main(){

    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
    
    double first = 1 , second = 2, temp;
    double err = 0.001;

    while(abs(second - first) >= err){
        cout << "x = " << second << endl;
        temp = second;
        second = get_x(first , second);
        first = temp;
    }
    cout << "x = " << second << endl;

    return 0;
}
