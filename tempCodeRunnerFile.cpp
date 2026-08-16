#include "bits/stdc++.h"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
const int inf = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5;
const int MOD = 1e9+7;
void tt()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int n,x,y,m,a,b,c,k,w,q,d;
string name,s,t;
void solve(){
	cin >> x >> a >> b;
	int ans = 0;
	if (a>=b){
		int xx = x*2;
		for (int i=1;i<MAX;i++){
			int tmp =  a*i+a*i*i;
			if (tmp>=xx){
				cout << i << endl;
				return;
			}
		}
	}else{
		int xx = x*2;
		for (int i=1;i<MAX;i++){
			int tmp =  a*i+a*i*i;
			if (tmp>=xx){
				ans = i;
				break;
			}
		}
		for (int j=ans;j>=0;j--){
			int tmp =  a*(j-1)+a*(j-1)*(j-1);
			tmp/=2;
			tmp+=(ans-j+1)*b;
			if 
		}
	}
	cout << ans << endl;
}

signed main()
{
	
	tt();
	int t;
	t=1;
//	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}