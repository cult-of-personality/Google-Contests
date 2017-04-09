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

// bool areAllSame(string s, int idx){
// 	char c = s[idx];
// 	FOR(i,idx,s.length()){
// 		if(s[i]!=c)
// 			return false;
// 	}
// 	return true;
// }

// int check(string s, int k){
// 	int idx = s.length()-k;
// 	int count = 0;
// 	FOR(i,0,idx){
// 		if(s[i]=='+')
// 			continue;
// 		count++;
// 		FOR(j,i,i+k){
// 			s[j] = (s[j]=='+') ? '-' : '+';
// 		}
// 	}
// 	if(!areAllSame(s,idx)){
// 		return -1;
// 	}
// 	return (s[idx]=='+') ? count : (count+1);
// }

void updateSingle(vi &tree, int idx, int v){
	while(idx<tree.size()){
		tree[idx]+=v;
		idx += (idx&-idx);
	}
}

//updates BIT range [a,b]
void updateRange(vi &tree, int a, int b){
	updateSingle(tree,a,1);
	updateSingle(tree,b+1,-1);
}

int querySingle(vi tree, int idx){
	int sum = 0;
	while(idx){
		sum += tree[idx];
		idx -= (idx&-idx);
	}
	return sum;
}

char getVal(char c, vi tree, int idx){
	int flips = querySingle(tree,idx+1);
	char d = (c=='+')?'-':'+';
	return (flips%2)?d:c;
}

bool areAllSame(string s, vi &tree, int idx){
	char ch = getVal(s[idx],tree,idx);
	FOR(i,idx,s.length()){
		if(getVal(s[i],tree,i)!=ch)
			return false;
	}
	return true;
}

int check(string s, int k){
	//initialize Binary Indexed Tree
	vi tree(1005,0);
	int idx = s.length()-k;
	int count=0;

	FOR(i,0,idx){
		if(getVal(s[i],tree, i) == '+')
			continue;
		count++;
		updateRange(tree,i+1, i+k);
	}

	if(!areAllSame(s,tree,idx)){
		return -1;
	}

	return (getVal(s[idx],tree,idx) == '+') ? count : (count+1);
}

int main(void) {
	int T, k;
	string s;
	cin>>T;
	FOR(t,0,T){
		cin>>s>>k;
		string r = s;
		reverse(r.begin(), r.end());
		int x = check(s,k);
		int y = check(r,k);
		cout<<"Case #"<<(t+1)<<": ";
		if(x<0 && y<0){
			cout<<"IMPOSSIBLE"<<endl;
		} else {
			cout<<min(x,y)<<endl;
		}
	}
}