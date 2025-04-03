#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define el '\n'
#define Beevo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int solve(int n, string &s){
    for(int bit = 29; bit >= 0; bit--){
        if(s.size()){
            s+= 'd', s+= '+';
        }
        if(n &(1 << bit)){
            s+= '1';

            if(s.size()> 1){
                s+= '+';}
        }
    }
    return count(s.begin(), s.end(), '+');
}

void testCase(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i< n; i++){
        cin >> a[i];
    }
    int sum = 0;
    string b[n];
    for(int i= n-1; i >=0; i--){
        int cur = a[i] + sum;

        sum += solve(cur, b[i]);
    }
    for (int i = 0; i < n; i++){
        cout << b[i];
    }
}

signed main(){
    Beevo

    int t = 1;
    while(t--){
        testCase();
    }
    return 0;
}