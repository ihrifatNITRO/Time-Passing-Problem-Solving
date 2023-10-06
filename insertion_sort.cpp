
#include <iostream>

#define INF 1000000000

using namespace std;

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cout << "Size of the array: "; // -INF 77 33 44 11 88 22 66 55 
    cin >> n;                      
    int a[n];                       
    a[0] = -INF;                   
    cout << "Inputs: ";
    for(int i=1;i<n;i++){
        cin >> a[i];
    }
    
    int k = 2;
    while(k < n){
        int ptr = k-1;
        int temp = a[k];
        while(temp < a[ptr]){
            a[ptr+1] = a[ptr];
            a[ptr] = temp;
            ptr = ptr - 1;
        }
        k++;
    }
    
    cout << "Outputs: ";
    for(int i=1;i<n;i++){
        cout << a[i] << " ";
    }

    return 0;
}
