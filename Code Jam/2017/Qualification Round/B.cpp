#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define SI short int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pbc pair<bool,char>
#define pcc pair<char,char>
#define vi vector<int>
#define vii vector<vector<int> >
#define vb vector<bool>
#define FOR(i,st,end) for(int (i)=(st);i<(end);i++)
#define FORD(i,st,end) for(int (i)=(st);i>=(end);i--)
#define FASTIO ios::sync_with_stdio(false);
#define ABS(i) ((i)>0)?(i):(-(i))
#define sci(m) scanf("%d",&m)
#define SORT(x) sort(x.begin(),x.end())
#define MOD 1000000007

string getString(LL n){
	string s;
	while(n){
		s += (char)('0'+n%10);
		n/=10;
	}
	reverse(s.begin(), s.end());
	return s;
}

bool isTidy(string s){
	//string s = getString(n);
	FOR(i,1,s.length()){
		if(s[i]<s[i-1])
			return false;
	}
	return true;
}

string getResult(LL n){
	string s = getString(n);
	if(isTidy(s))
		return s;

	string least(s.length(),'1');
	if(s<least)
		return string(s.length()-1,'9');

	int pivot = -1;
	FOR(i,1,s.length()){
		if(s[i]<s[i-1]){
			pivot = i-1;
			break;
		}
	}

	//find the farthest digit from left and the nearest to pivot decreasing whom won't upset the balance
	int start = pivot;
	while(start>0){
		if(s[start-1]==s[start])
			start--;
		else break;
	}
	s[start]--;
	return s.substr(0,start+1) + string(s.length()-start-1,'9');
}

int main(){
	int T;
	LL n;
	cin>>T;
	FOR(t,0,T){
		cin>>n;
		string r = getResult(n);
		cout<<"Case #"<<(t+1)<<": "<<r<<endl;
	}
	return 0;
}