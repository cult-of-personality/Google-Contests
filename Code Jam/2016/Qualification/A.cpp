#include <bits/stdc++.h>
using namespace std;
#define LL long long

int getRemaining(LL m, vector<bool> &d, int r){
    while(m){
        int x = m%10;
        if(!d[x]){
            d[x] = true;
            r--;
        }
        m /= 10;
    }
    return r;
}

long getLastNumber(LL n) {
    if(n == 0){
        return -1;
    }
    vector<bool> digit(10, false);
    int remaining = 10;
    long multiple = 0;
    do{
        multiple += n;
        remaining = getRemaining(multiple, digit, remaining);
    }while(remaining > 0);

    return multiple;
}

int main(void){
    int	T,n;
    scanf(" %d", &T);

    for(int t=1; t<=T; t++) {
        scanf(" %d", &n);
        LL result = getLastNumber(n);
        printf("Case #%d: ", t);
        if(result>0)
            printf("%lld\n", result);
        else printf("INSOMNIA\n");
    }

    return 0;
}