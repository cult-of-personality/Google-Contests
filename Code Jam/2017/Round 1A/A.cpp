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

char MISSING = '?';

void completeRow(vector<vector<char> > &grid, vii pivots, int r, int C){
    int start = 0;
    FOR(j,0,pivots[r].size()){
        FOR(k,start,pivots[r][j]){
            grid[r][k] = grid[r][pivots[r][j]];
        }
        start = pivots[r][j]+1;
    }
    FOR(j,start,C){
        grid[r][j] = grid[r][pivots[r][pivots[r].size()-1]];
    }
}

void completeRows(vector<vector<char> > &grid, vii pivots, int R, int C){
    FOR(i,0,pivots.size()){
        if(pivots[i].empty()){
            continue;
        }
        completeRow(grid,pivots,i,C);
    }
}

vii getPivots(vector<vector<char> > grid, int R, int C){
    vii pivots(R);
    FOR(i,0,R){
        vi alphabets;
        FOR(j,0,C){
            if(grid[i][j] != MISSING)
                alphabets.pb(j);
        }
        pivots[i] = alphabets;
    }
    return pivots;
}

void printGrid(vector<vector<char> > grid, vi copyRow, int R, int C){
    FOR(i,0,R){
        FOR(j,0,C){
            printf("%c",grid[copyRow[i]][j]);
        }
        printf("\n");
    }
}

void solve(vector<vector<char> > &grid, int R, int C){
    vii pivots = getPivots(grid,R,C);
    completeRows(grid, pivots,R,C);

    vi copyRow(R,-1);
    vi nonEmptyRows;
    FOR(i,0,R){
        if(!pivots[i].empty()){
            copyRow[i] = i;
            nonEmptyRows.pb(i);
        }
    }
    int start = 0;
    FOR(i,0,nonEmptyRows.size()){
        FOR(k,start,nonEmptyRows[i]){
            copyRow[k] = nonEmptyRows[i];
        }
        start = nonEmptyRows[i]+1;
    }
    FOR(i,start,R){
        copyRow[i] = nonEmptyRows[nonEmptyRows.size()-1];
    }

    printGrid(grid,copyRow,R,C);
}

int main(void){
    int T,R,C;
    string s;
    sci(T);

    FOR(t,1,T+1){
        sci(R);
        sci(C);
        vector<vector<char> > grid(R,vector<char>(C));

        FOR(r,0,R){
            cin>>s;
            FOR(j,0,s.length()){
                grid[r][j] = s[j];
            }
        }
        printf("Case #%d:\n",t);
        solve(grid,R,C);
    }
    return 0;
}