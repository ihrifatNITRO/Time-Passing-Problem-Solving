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

vector<ll>v;

void write_file(ll n){
   fstream in; // open file for read and write
   in.open("Algo_Lab.txt");
   
   srand(time(0)); // random number generation
   foi(i,0,n){
   	 in << rand() << " ";
   }
   in.close(); // close file
}

void read_file(ll n){
	fstream in; // open file for read and write
	in.open("Algo_Lab.txt");

	ll a;
	while(in >> a){ // take input until end of number
		v.pb(a);
	}
	in.close(); // close file
}

void linear(ll n, ll num){
	ll cnt = 0;
	for(auto i : v){
		cnt++;
		if(i == num){
			cout << "Linear Position: " << cnt-1 << " Steps: " << cnt << endl;
			return;
		}
	}
	cout << "Linear Position: " << -1 << " Steps: " << cnt << endl;
}

void normal_bin(ll left, ll right, ll num){
	ll cnt = 0;
	while(left <= right){
		cnt++;
		ll mid = (left+right) / 2;
		if(v[mid] == num){
			cout << "Binary Position: " << mid << " Steps: " << cnt << endl;
			return;
		}
		else if(v[mid] < num){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout << "Binary Position: " << -1 << " Steps: " << cnt << endl;
}

void recursive_bin(ll left, ll right, ll num, ll cnt){
	cnt++;
	if(left == right){
		if(v[left] == num){
			cout << "Recusive Position: " << left << " Steps: " << cnt << endl;
		}
		else{
			cout << "Recusive Position: " << -1 << " Steps: " << cnt << endl;
		}
		return;
	}
	else{
		ll mid = (left+right) / 2;
		if(v[mid] == num){
			cout << "Recusive Position: " << mid << " Steps: " << cnt << endl;
			return;
		}
		else if(v[mid] < num){
			return recursive_bin(mid+1, right, num, cnt);
		}
		else{
			return recursive_bin(left, mid-1, num, cnt);
		}
	}
}

int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif

   fast

   ll n, num; // input size
   cin >> n >> num;

   write_file(n); // generating numbers and saving on file
   read_file(n); // reading generated numbers on a vector

   linear(n, num);

   sort(v.begin() , v.end());
   normal_bin(0, n-1, num);
   recursive_bin(0, n-1, num, 0);

   
   return 0;
}
