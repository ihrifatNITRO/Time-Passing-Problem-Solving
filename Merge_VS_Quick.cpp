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

void write_file(ll n){
   fstream in; // open file for read and write
   in.open("Algo_Lab.txt");
   
   srand(time(0)); // random number generation
   foi(i,0,n){
   	 in << rand()%500 - 123 << " ";
   }
   in << "\n";
   in.close(); // close file
}
void read_file(ll n, vector<ll>& asc, vector<ll>& des, vector<ll>& avg, vector<ll>& asc1, vector<ll>& des1, vector<ll>& avg1){
	fstream in;
	in.open("Algo_Lab.txt");

	ll a;
	while(in >> a){
		asc.pb(a); des.pb(a); avg.pb(a);
		asc1.pb(a); des1.pb(a); avg1.pb(a);
	}
	in.close();
}

void merge(vector<ll>& v2, ll l, ll m, ll r)
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
        v2[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        v2[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<ll>& v, ll l, ll r)
{
    if (l < r) {
        ll m = l + (r - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
 
        merge(v, l, m, r);
    }
}

// Quick sort
int part(vector<ll>& v, ll low, ll high) {
    
  ll pivot = v[high];
  ll i = (low - 1);

  for (ll j = low; j < high; j++) {
  	cnt++;
    if (v[j] <= pivot) {
      i++;
      swap(v[i], v[j]);
    }
  }
  
  swap(v[i + 1], v[high]);
  
  return (i + 1);
}

void quickSort(vector<ll>& v, ll low, ll high) {
  if (low < high) {
    ll pi = part(v, low, high);
    quickSort(v, low, pi - 1);

    quickSort(v, pi + 1, high);
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif

   fast

   ll n; cin >> n;
   vector<ll>asc, des, avg, asc1, des1, avg1;
   write_file(n);
   read_file(n,asc,des,avg,asc1,des1,avg1);

   cout << "Merge Sort:" << nl;
   sort(asc.begin() , asc.end());
   mergeSort(asc, 0, n-1);
   cout << "Best Case: " << cnt << nl;
   cnt = 0;
   sort(avg.begin(), avg.end()-(n/2), greater<ll>());
   mergeSort(avg, 0, n-1);
   cout << "Avarage Case: " << cnt << nl;
   cnt = 0;
   mergeSort(des, 0, n-1);
   cout << "Worst Case: " << cnt << nl;
   cnt = 0;

   cout << nl;
   cout << "Quick Sort:" << nl;
   //sort(asc1.begin() , asc1.end());
   quickSort(asc1, 0, n-1);
   cout << "Best Case: " << cnt << nl;
   cnt = 0;
   sort(avg1.begin(), avg1.end()-(n/2), greater<ll>());
   quickSort(avg1, 0, n-1);
   cout << "Avarage Case: " << cnt << nl;
   cnt = 0;
   sort(des1.begin(), des1.end());
   quickSort(des1, 0, n-1);
   cout << "Worst Case: " << cnt << nl;

   
   return 0;
}