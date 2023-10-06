#include<bits/stdc++.h>
#include<iostream>

using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
    	cin >> a[i];
    }

    for(int i=0;i<n-1;i++){
    	int mini = a[i];
    	int loc = i;
    	for(int j=i+1;j<n;j++){
    		if(mini > a[j]){
    			mini = a[j];
    			loc = j;
    		}
    	}

    	swap(a[i] , a[loc]);
    }

    for(int i=0;i<n;i++){
    	cout << a[i] << " ";
    }

}