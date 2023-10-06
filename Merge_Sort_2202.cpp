/* In the name of ALLAH */

#include<bits/stdc++.h>
// MAXIMUM and MINIMUM elements
#define mx_ari(a)       *max_element(a , a+sizeof(a)/4)
#define mn_ari(a)       *min_element(a , a+sizeof(a)/4)
#define mx_arl(a)       *max_element(a , a+sizeof(a)/8)
#define mn_arl(a)       *min_element(a , a+sizeof(a)/8)
#define mx_vec(v)       *max_element(v.begin() , v.end())
#define mn_vec(v)       *min_element(v.begin() , v.end())
// COUNT the occurence of an element
#define cnt_ari(a,b)    count(a , a+sizeof(a)/4 , b)
#define cnt_arl(a,b)    count(a , a+sizeof(a)/8 , b)
#define cnt_vec(v,b)    count(v.begin() , v.end() , b)
// LOOPs
#define foi(i,a,n)      for(int i=a;i<n;i++)
#define fol(i,a,n)      for(long long i=a;i<n;i++)
// NEWLINEs
#define nl              "\n"
// PAIRs and PUSHbacks
#define mp             make_pair
#define pb             emplace_back
// IMPORTANTs
#define ll             long long
#define ull            unsigned long long int
#define mod            1000000007
#define lcm(a,b)       (a*b) / __gcd(a,b)
#define fact(a)/* 0 to 4 */ ceil(sqrt(2*3.1416*a) * pow((a / 2.7183), a))
#define yes            cout << "YES" << "\n"
#define no             cout << "NO" << "\n"
#define fast  std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll cnt;
vector<ll>v1,v2,v3;
void write_file(ll n){
   fstream in; // open file for read and write
   in.open("Algo_Lab.txt");
   
   srand(time(0)); // random number generation
   foi(i,0,n){
   	 in << rand()%mod - 13337 << " ";
   }
   in << "\n";
   in.close(); // close file
}
void read_file(ll n){
	fstream in;
	in.open("Algo_Lab.txt");

	ll a;
	while(in >> a){
		v1.pb(a); v2.pb(a); v3.pb(a);
	}
	in.close();
}

void bubble(ll n){
  foi(i,0,n-1){
    cnt++;
    foi(j,0,n-1-i){
      cnt++;
      if(v1[j] > v1[j+1]) swap(v1[j] , v1[j+1]);
    }
  }
}

void merge(ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 = r - m;
 
    ll L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = v2[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v2[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        cnt++;
        if (L[i] <= R[j]) {
            v2[k] = L[i];
            i++;
        }
        else {
            v2[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        cnt++;
        v2[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        cnt++;
        v2[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(ll l, ll r)
{
    if (l < r) {
        cnt++;
        ll m = l + (r - l) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);
 
        merge(l, m, r);
    }
}

void insertion(ll n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        cnt++;
        key = v3[i];
        j = i - 1;
 
        while (j >= 0 && v3[j] > key)
        {
            cnt++;
            v3[j + 1] = v3[j];
            j--;
        }
        v3[j + 1] = key;
    }
}

int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif

   fast

   // Merge sort, bubble sort, insertion sort
   ll n; cin >> n;
   write_file(n);
   read_file(n);

   cout << "Input size: " << n << nl;
   bubble(n);
   cout << "Bubble: " << cnt << nl;

   cnt = 0;
   mergeSort(0, n-1);
   cout << "Merge: " << cnt << nl;

   cnt = 0;
   insertion(n);
   cout << "Insertion: " << cnt << nl;

   
   return 0;
}